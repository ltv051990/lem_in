/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:55:52 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 12:55:53 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
void	ft_read_data(t_all_data *main_uk)
{
	char *line;
/*
*** first check when i see nb_ants 
*/
/*	while (main_uk->fl_ants != 1)
	{
		if (get_next_line(0, &line) == 0)
			ft_error("EMPTY INPUT");
		if (*line == '#')
		{
			if (ft_strequ(line, "##end"))
					ft_error("INCORECT END");
			else if (ft_strequ(line, "##start"))
				ft_error("INCORECT START");
			else if (line[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			else if (line[1] == '#')
				ft_strdel(&line);
		}
		else if (ft_isdigit(*line))
			ft_check_nb_ants(main_uk, &line);
		else
			ft_error("INCORECT NB ANTS");
	}
/*
*** first check when i see nb_ants
*/

/*
*** next check rooms
*/
/*
	int ret = 1;
	while (ret && main_uk->cor_input)
	{
		if ((ret = get_next_line(0, &line)) == 0)
			main_uk->cor_lines = 0;
		if (ret != 0 && *line == '#')
		{
			if (ft_strequ(line, "##end"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				check_end(main_uk, 1);
			}
			else if (ft_strequ(line, "##start"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				check_start(main_uk, 1);
			}
			else if (line[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			else if (line[1] == '#')
				ft_strdel(&line);
		}
		else if (ret != 0)
			check_rooms(main_uk, line);
 	}
 
/*
*** check lines
*/
 /*	if (main_uk->fl_start == 0 || main_uk->fl_end == 0)
 		ft_error("start??? != end???");
	ret = 1;
	while (main_uk->cor_lines)
	{
		if ((ret = get_next_line(0, &line)) == 0)
			break ;
		if (*line == '#')
		{
			if (ft_strequ(line, "##end"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				ft_error("BAD END IN LINKS");
			}
			else if (ft_strequ(line, "##start"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				ft_error("BAD START IN LINKS");
			}
			else if (line[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			else if (line[1] == '#')
				ft_strdel(&line);
			}
			else
				check_lines(main_uk, line);
	}
 	if (main_uk->fl_start == 0 || main_uk->fl_end == 0 || main_uk->fl_lines == 0)
 		ft_error("NOT FULL INPUT");
}*/

void	algo(t_all_data *main_uk)
{
	t_rooms **r_start;
	t_rooms *r_now;

	t_way	**w_start;
	t_way	*w_now;

	t_gps **g_start;
	t_gps *g_now;

	r_start = &main_uk->rnext; //rooms_start
	r_now = *r_start;			// reserve rooms start

	g_start = &main_uk->gnext;
	lst_gps_pb(g_start, lst_gps(NULL));
	w_start = &main_uk->gnext->uk_way; //way_start
	w_now = (*w_start);

 	r_now->empty = 1;
 	lst_way_pb(w_start, lst_way((r_now->room))); // include start

	while (check_visit_all(r_start))
	{
		if ((r_now = next_room(r_start, r_now)) == NULL)
			break ;//ft_error("No way!!!");
		r_now->empty = 1;
		lst_way_pb(w_start, lst_way(r_now->room));
		if (r_now->position == 2)
		{
			r_now->empty = 0;
			break ;
		}
	}
// ///////////////////////////////////////////////////////
// //////////////////PRINT WAY NOW ///////////////////////
// ///////////////////////////////////////////////////////
w_now = main_uk->gnext->uk_way;
printf("\nStart there   -> %s\n", w_now->name);
w_now = w_now->next;
while (w_now)
	{
		// if (w_now->next == NULL)
		// 	printf("\nThe end there -> %s\n", w_now->name);
		// else
			printf("\nNow I am here -> %s\n", w_now->name);
		w_now = w_now->next;
	}

	lst_gps_pb(g_start, lst_gps(NULL));
	w_start = &main_uk->gnext->next->uk_way; //way_start
	w_now = (*w_start);
	r_now = (*r_start);
 	lst_way_pb(w_start, lst_way((r_now->room))); // include start

////////////////////////////////////////////////
	while (check_visit_all(r_start))
	{
		if ((r_now = next_room(r_start, r_now)) == NULL)
			ft_error("No way!!!");
		r_now->empty = 1;
		lst_way_pb(w_start, lst_way(r_now->room));
		if (r_now->position == 2)
		{
			r_now->empty = 0;
			break ;
		}
	}
// ///////////////////////////////////////////////////////
// //////////////////PRINT WAY NOW ///////////////////////
// ///////////////////////////////////////////////////////
w_now = (*w_start);
printf("\n\n\n\nStart there   -> %s\n", w_now->name);
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


