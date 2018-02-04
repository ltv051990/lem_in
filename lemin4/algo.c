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

void	algo(t_all_data *main_uk)
{
	t_rooms **r_start;
	t_rooms *r_now;
//////////////////////////////////////////////////
	t_ngbor *n_start;
	t_ngbor *n_now;
//////////////////////////////////////////////////
	t_way	*w_start;
	t_way	*w_now;
//////////////////////////////////////////////////
	r_start = &main_uk->rnext; //rooms_start
	r_now = *r_start;			// reserve rooms start
	w_start = main_uk->wnext; //way_start
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
	r_now->empty = 1;
	n_start = r_now->down;
	lst_way_pb(&w_start, lst_way((r_now->room))); // include start
//////////////////////////////////////////////////


	// lst_way_pb(&w_start, lst_way(n_start->ngbor));
	// r_now = ft_srch_back_room(r_start, r_now->down->ngbor);
	// r_now->empty = 1;
	// lst_way_pb(&w_start, lst_way(r_now->down->ngbor));
	// r_now = ft_srch_back_room(r_start, r_now->down->ngbor);
	// r_now->empty = 1;

//////////////////////////////////////////////////////

	while (check_visit_all(r_start))
	{
		if ((r_now = next_room(r_start, r_now)) == NULL)
			ft_error("No way!!!");
		r_now->empty = 1;
		lst_way_pb(&w_start, lst_way(r_now->room));
		if (r_now->position == 2)
			break ;
	}


///////////////////////////////////////////////////////
//////////////////PRINT WAY NOW ///////////////////////
///////////////////////////////////////////////////////
w_now = w_start;
printf("\nStart there   -> %s\n", w_now->name);
w_now = w_now->next;
while (w_now)
	{
		if (w_now->next == NULL)
			printf("\nThe end there -> %s\n", w_now->name);
		else
			printf("\nNow I am here -> %s\n", w_now->name);
		w_now = w_now->next;
	}
}
//////////////////////////////////////////////////
