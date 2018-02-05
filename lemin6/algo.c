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
	t_rooms **room_str;                            // старт кімнати
	t_rooms *room_now;							   // кімната зараз

	t_way	**way_str;								// старт нового шляху
	t_way	*way_now;								// поточний шлях

	t_gps **gps_str = NULL;							// старт набору шляхів
	t_gps *gps_now;									// поточна 

	room_str = &main_uk->rnext; //rooms_start
	room_now = *room_str;			// reserve rooms start

	gps_str = &main_uk->gnext;
	gps_now = *gps_str;

	lst_gps_pb(gps_str, lst_gps(lst_way(room_now)));
	//main_uk->gnext = gps_str;
	printf("\n\n\n\n\n\n\n%s\n\n\n\n", main_uk->gnext->uk_way->ukaz->room);
	while(gps_now)
	{
		/*поки є сусіди (і я їх ще не відвідав) самої нижньої моєї кімнати
		я рухаюся вниз і добавляю її останньою до списку наступних кімнат
		 але перед цим я копіюю ту, що зараз в мене є*/


		/*
		коли в моєї кімнати сусіди закінчилися (тобто я всіх їх вже відвідав
		або) а їх не має взагалі я переходжу до наступного елемента листа, але
		перед я фрішу цю ноду і переходжу до наступної ноди)))
		*/
		gps_now = gps_now->next;
	}
}