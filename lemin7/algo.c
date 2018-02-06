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
		way_now = gps_now->uk_way;
		while (way_now->next)
			way_now = way_now->next;
		/*поки є сусіди (і я їх ще не відвідав) самої нижньої моєї кімнати
		я рухаюся вниз і добавляю її останньою до списку наступних кімнат
		 але перед цим я копіюю ту, що зараз в мене є*/
		ng_str = way_now->ukaz->down;
	//	printf("rooms %s\n", ng_str->ngbor);
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

		// if (!lala)
		// 	free(поточну ноду)

		/*перед фрішенням поточної ноди GPS я повинен перевірити чи не має там
		фінішу*/
		gps_now = gps_now->next;
	}
}