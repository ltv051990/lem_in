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

// void	algo(t_all_data *main_uk)
// {
// 	t_rooms **r_start;
// 	t_rooms *r_now;

// 	t_way	**w_start;
// 	t_way	*w_now;

// 	t_gps **g_start;
// 	t_gps *g_now;

// 	r_start = &main_uk->rnext; //rooms_start
// 	r_now = *r_start;			// reserve rooms start

// 	g_start = &main_uk->gnext;
// 	lst_gps_pb(g_start, lst_gps(NULL));
// 	w_start = &main_uk->gnext->uk_way; //way_start
// 	w_now = (*w_start);

//  	r_now->empty = 1;
//  	lst_way_pb(w_start, lst_way((r_now->room))); // include start

// 	while (check_visit_all(r_start))
// 	{
// 		if ((r_now = next_room(r_start, r_now)) == NULL)
// 			break ;//ft_error("No way!!!");
// 		r_now->empty = 1;
// 		lst_way_pb(w_start, lst_way(r_now->room));
// 		if (r_now->position == 2)
// 		{
// 			r_now->empty = 0;
// 			break ;
// 		}
// 	}
// // ///////////////////////////////////////////////////////
// // //////////////////PRINT WAY NOW ///////////////////////
// // ///////////////////////////////////////////////////////
// w_now = main_uk->gnext->uk_way;
// printf("\nStart there   -> %s\n", w_now->name);
// w_now = w_now->next;
// while (w_now)
// 	{
// 		// if (w_now->next == NULL)
// 		// 	printf("\nThe end there -> %s\n", w_now->name);
// 		// else
// 			printf("\nNow I am here -> %s\n", w_now->name);
// 		w_now = w_now->next;
// 	}

// 	lst_gps_pb(g_start, lst_gps(NULL));
// 	w_start = &main_uk->gnext->next->uk_way; //way_start
// 	w_now = (*w_start);
// 	r_now = (*r_start);
//  	lst_way_pb(w_start, lst_way((r_now->room))); // include start

// ////////////////////////////////////////////////
// 	while (check_visit_all(r_start))
// 	{
// 		if ((r_now = next_room(r_start, r_now)) == NULL)
// 			ft_error("No way!!!");
// 		r_now->empty = 1;
// 		lst_way_pb(w_start, lst_way(r_now->room));
// 		if (r_now->position == 2)
// 		{
// 			r_now->empty = 0;
// 			break ;
// 		}
// 	}
// // ///////////////////////////////////////////////////////
// // //////////////////PRINT WAY NOW ///////////////////////
// // ///////////////////////////////////////////////////////
// w_now = (*w_start);
// printf("\n\n\n\nStart there   -> %s\n", w_now->name);
// w_now = w_now->next;
// while (w_now)
// 	{
// 		if (w_now->next == NULL)
// 			printf("\nThe end there -> %s\n", w_now->name);
// 		else
// 			printf("\nNow I am here -> %s\n", w_now->name);
// 		w_now = w_now->next;
// 	}
// }
//////////////////////////////////////////////////
/*
void	algo(t_all_data *main_uk)
{
	t_rooms **room_str = NULL;      	                   // старт кімнати
	t_rooms *room_now = NULL;							   // кімната зараз

	t_way	*way_str = NULL;								// старт нового шляху
	t_way	*way_now = NULL;								// поточний шлях

	t_gps **gps_str = NULL;									// старт набору шляхів
	t_gps *gps_now = NULL;									// поточна 

	t_ngbor *ng_str = NULL;									//старт списку сусідів
	room_str = &main_uk->rnext; 							//rooms_start
	room_now = *room_str;									// reserve rooms start

	gps_str = &main_uk->gnext;
	lst_gps_pb(gps_str, lst_gps(lst_way(room_now)));
	room_now->empty = 1;
	gps_now = *gps_str;
	while(gps_now)
	{
		if (happy_end(gps_now->uk_way))
		{
			gps_now->finish = 1;
			gps_now = gps_now->next;
			++(main_uk->fl);
		}
		if (gps_now == NULL)
			break ;
		way_now = gps_now->uk_way;
		while (way_now->next)
			way_now = way_now->next;
		/*поки є сусіди (і я їх ще не відвідав) самої нижньої моєї кімнати
		я рухаюся вниз і добавляю її останньою до списку наступних кімнат
		 але перед цим я копіюю ту, що зараз в мене є*/
/*		ng_str = way_now->ukaz->down;
		while (ng_str)
		{
			if (check_visit_one(room_str, ng_str->ngbor))
			{
				way_str = NULL;
				room_now = ft_srch_back_room(room_str, ng_str->ngbor);
				//////поставити кімнату як відвідувану
				if (room_now->position != 2)
					room_now->empty = 1;
				// створюю копію поточного списку lst_way
				lst_way_copy(&way_str, gps_now->uk_way);
				// додаю поточну кімнату до поточного списку lst_way
				lst_way_pb(&way_str, lst_way(room_now));				
				//створюю нову ноду листа, що містить новий список
				lst_gps_pb(gps_str, lst_gps((way_str)));
				///////додати нову ноду списку GPS яка скопіюю поточну
			}
			ng_str = ng_str->next;
		}
		/*
		коли в моєї кімнати сусіди закінчилися (тобто я всіх їх вже відвідав
		або) а їх не має взагалі я переходжу до наступного елемента листа, але
		перед я фрішу цю ноду і переходжу до наступної ноди)))
		*/

		/*перед фрішенням поточної ноди GPS я повинен перевірити чи не має там
		фінішу*/
/*		gps_now = gps_now->next;
	}
}*/

void	algo(t_all_data *main_uk)
{
	t_rooms *room_now = NULL;
	t_way	*way_str = NULL;
	t_way	*way_now = NULL;
	t_gps *gps_now = NULL;
	t_ngbor *ng_str = NULL;

	room_now = main_uk->rnext;;
	lst_gps_pb(&main_uk->gnext, lst_gps(lst_way(room_now)));
	room_now->empty = 1;
	gps_now = main_uk->gnext;
	while(gps_now)
	{
		if (happy_end(gps_now->uk_way) && (gps_now->fn = 1) && (++(main_uk->fl)))
			if ((gps_now = gps_now->next) == NULL)
				break ;
		way_now = gps_now->uk_way;
		while (way_now->next)
			way_now = way_now->next;
		ng_str = way_now->ukaz->down;
		while (ng_str)
		{
			if (check_visit_one(&main_uk->rnext, ng_str->ngbor))
			{
				way_str = NULL;
				room_now = ft_srch_back_room(&main_uk->rnext, ng_str->ngbor);
				if (room_now->position != 2)
					room_now->empty = 1;
				lst_way_copy(&way_str, gps_now->uk_way);
				lst_way_pb(&way_str, lst_way(room_now));
				lst_gps_pb(&main_uk->gnext, lst_gps((way_str)));
			}
			ng_str = ng_str->next;
		}
		gps_now = gps_now->next;
	}
}