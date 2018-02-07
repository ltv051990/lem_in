/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:50:54 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 19:50:55 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** Return one when when find end in way
*/

int				happy_end(t_way *start)
{
	t_way		*res;

	res = start;
	while (res->next)
		res = res->next;
	if (res->ukaz->position == 2)
		return (1);
	return (0);
}

/*
*** add to stack new line
*/

void			add_stack(t_gps *gps_now, t_all_data *main_uk, t_ngbor *ng_str)
{
	t_way		*way_str;
	t_rooms		*room_now;

	way_str = NULL;
	room_now = NULL;
	room_now = ft_srch_back_room(&main_uk->rnext, ng_str->ngbor);
	if (room_now->position != 2)
		room_now->empty = 1;
	lst_way_copy(&way_str, gps_now->uk_way);
	lst_way_pb(&way_str, lst_way(room_now));
	lst_gps_pb(&main_uk->gnext, lst_gps((way_str)));
}

/*
*** add to stack new line
*/

t_way			*return_way(t_gps *gs_nw)
{
	t_way		*way_now;

	way_now = NULL;
	way_now = gs_nw->uk_way;
	while (way_now->next)
		way_now = way_now->next;
	return (way_now);
}

/*
*** defolt per in algo function
*/

void			ft_def(t_rooms **room_now, t_way **way_now, t_gps **gs_nw,
				t_ngbor **ng_str)
{
	room_now = NULL;
	way_now = NULL;
	gs_nw = NULL;
	ng_str = NULL;
}

void			algo(t_all_data *main_uk)
{
	t_rooms		*room_now;
	t_way		*way_now;
	t_gps		*gs_nw;
	t_ngbor		*ng_str;

	ft_def(&room_now, &way_now, &gs_nw, &ng_str);
	room_now = main_uk->rnext;
	lst_gps_pb(&main_uk->gnext, lst_gps(lst_way(room_now)));
	room_now->empty = 1;
	gs_nw = main_uk->gnext;
	while (gs_nw)
	{
		if (happy_end(gs_nw->uk_way) && (gs_nw->fn = 1) && (++(main_uk->fl)))
			if ((gs_nw = gs_nw->next) == NULL)
				break ;
		way_now = return_way(gs_nw);
		ng_str = way_now->ukaz->down;
		while (ng_str)
		{
			if (check_visit_one(&main_uk->rnext, ng_str->ngbor))
				add_stack(gs_nw, main_uk, ng_str);
			ng_str = ng_str->next;
		}
		gs_nw = gs_nw->next;
	}
}

/*
**while there are neighbors (and I have not visited them yet)
**at the bottom of my room I'm moving down and add it to
**the last list of the next rooms but before that I copy
**that which I have now when in my room neighbors have ended
**(that is, I have already visited them all
**If I do not have them at all, but I'm moving to the next
**element of the letter before I fuss this node and move
**on to the next node
*/
