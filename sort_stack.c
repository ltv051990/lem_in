/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:18:21 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/07 17:18:22 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** write nb of steps in way to the t_gps node
*/

void		find_step_way(t_all_data *main_uk)
{
	t_gps	*start;

	start = main_uk->gnext;
	while (start)
	{
		start->steps = count_steps(start);
		start = start->next;
	}
}

/*
*** write nb of steps in way to the t_gps node
*/

void		ft_max_way_nb(t_all_data *main_uk)
{
	int		start;
	int		finish;
	t_rooms	*cur;

	start = 0;
	finish = 0;
	cur = main_uk->rnext;
	start = count_nbbor(cur->down);
	while (cur->position != 2)
	{
		cur = cur->next;
		if (cur == NULL)
			ft_error("Sorry", main_uk);
	}
	finish = count_nbbor(cur->down);
	main_uk->nb_ways = start < finish ? start : finish;
}

/*
*** find way that not repeat
*/

void		find_use_way(t_gps *gstart)
{
	t_gps	*gcur;
	t_way	*wfirst;
	t_way	*wcur;
	int		res;

	gcur = gstart->next;
	while (gcur && (res = 1))
	{
		wfirst = gstart->uk_way;
		while (wfirst && (wcur = gcur->uk_way))
		{
			while (wcur)
			{
				if (ft_strequ(wfirst->ukaz->room, wcur->ukaz->room))
					if (wcur->ukaz->position != 2 && wcur->ukaz->position != 1)
						res = 0;
				wcur = wcur->next;
			}
			wfirst = wfirst->next;
		}
		gcur->use = (res == 1) ? 1 : 0;
		gcur = gcur->next;
	}
}

/*
*** fint nb of not repeat ways in stack;
*/

int			nb_ways_in_stack(t_gps *start)
{
	int		count;

	count = 0;
	while (start)
	{
		count++;
		start = start->next;
	}
	return (count);
}

/*
*** return only walid steps
*/

void		sort_stack(t_all_data *main_uk)
{
	int		res;
	t_gps	*cur;

	res = 0;
	ft_max_way_nb(main_uk);
	del_stack_fl(main_uk);
	main_uk->gnext->use = 1;
	if (main_uk->nb_ways == 1)
		del_stack_use(main_uk);
	find_step_way(main_uk);
	cur = main_uk->gnext;
	while (cur)
	{
		++res;
		if (res >= main_uk->nb_ways)
			break ;
		find_use_way(cur);
		del_stack_use(main_uk);
		cur = cur->next;
	}
}
