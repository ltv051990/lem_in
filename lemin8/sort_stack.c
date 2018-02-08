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
*** free way->down from stack when main->fn equal 0
*/

void	free_way_down(t_gps *now)
{
	t_way *down;
	t_way *res;

	down = now->uk_way;
	while (down)
	{
		res = down;
		down = down->next;
		free(res);
	}
	free(now);
}

/*
*** free way->down from stack when main->fn equal 0
*/

void	del_stack_fl(t_all_data *main_uk)
{
	t_gps *cur;
	t_gps *prev;

	cur = main_uk->gnext;
	prev = cur;
	while(cur)
	{
		if ((cur->fn == 0) && (cur == main_uk->gnext))
		{
			prev = cur->next;
			free_way_down(cur);
			cur = prev;
			main_uk->gnext = cur;
		}
		else if (cur->fn == 0)
		{
			prev->next = cur->next;
			free_way_down(cur);
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

/*
*** free way->down from stack when main->fn equal 0
*/

void	del_stack_use(t_all_data *main_uk)
{
	t_gps *cur;
	t_gps *prev;

	cur = main_uk->gnext;
	prev = cur;
	while(cur)
	{
		if ((cur->use == 0) && (cur == main_uk->gnext))
		{
			prev = cur->next;
			free_way_down(cur);
			cur = prev;
			main_uk->gnext = cur;
		}
		else if (cur->use == 0)
		{
			prev->next = cur->next;
			free_way_down(cur);
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

/*
*** count nb of steps in way
*/

int		count_steps(t_gps *cur)
{
	t_way *start;
	int count;

	count = 0;
	start = cur->uk_way;
	while (start)
	{
		++count;
		start = start->next;
	}
	return (count);

}

/*
*** count nb of ngbords
*/

int	count_nbbor(t_ngbor *uk)
{
	int res;

	res = 0;
	while (uk)
	{
		res++;
		uk = uk->next;
	}
	return (res);
}

/*
*** write nb of steps in way to the t_gps node
*/

void	find_step_way(t_all_data *main_uk)
{
	t_gps *start;

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

void	ft_max_way_nb(t_all_data *main_uk)
{
	int start;
	int finish;
	t_rooms *cur;

	start = 0;
	finish = 0;
	cur = main_uk->rnext;
	start = count_nbbor(cur->down);
	while (cur->position != 2)
	{
		cur = cur->next;
		if (cur == NULL)
			ft_error("Sorry");
	}
	finish = count_nbbor(cur->down);
	main_uk->nb_ways = start < finish ? start : finish;
}


/*
*** find way that not repeat
*/

void	find_use_way(t_gps *gstart)
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
				printf("wfirst->ukaz->room %s wcur->ukaz->room %s\n",wfirst->ukaz->room, wcur->ukaz->room);
				if (ft_strequ(wfirst->ukaz->room, wcur->ukaz->room))
					if (wcur->ukaz->position != 2 && wcur->ukaz->position != 1)
					{
						printf("%s\n", "lala");
						res = 0;
					}
				wcur = wcur->next;
			}
			wfirst = wfirst->next;
		}
		res == 1 ? (gcur->use = 1) : (gcur->use = 0);
		gcur = gcur->next;
	}
}

/*
*** fint nb of not repeat ways in stack;
*/

int		nb_ways_in_stack(t_gps *start)
{
	int count;

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

void	sort_stack(t_all_data *main_uk)
{
	int	res;
	t_gps *cur;

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










