/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:08:55 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/10 15:08:55 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** free way->down from stack when main->fn equal 0
*/

void		free_way_down(t_gps *now)
{
	t_way	*down;
	t_way	*res;

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

void		del_stack_fl(t_all_data *main_uk)
{
	t_gps	*cur;

	cur = main_uk->gnext;
	main_uk->prev = cur;
	while (cur)
	{
		if ((cur->fn == 0) && (cur == main_uk->gnext))
		{
			main_uk->prev = cur->next;
			free_way_down(cur);
			cur = main_uk->prev;
			main_uk->gnext = cur;
		}
		else if (cur->fn == 0)
		{
			main_uk->prev->next = cur->next;
			free_way_down(cur);
			cur = main_uk->prev->next;
		}
		else
		{
			main_uk->prev = cur;
			cur = cur->next;
		}
	}
}

/*
*** free way->down from stack when main->fn equal 0
*/

void		del_stack_use(t_all_data *main_uk)
{
	t_gps	*cur;

	cur = main_uk->gnext;
	main_uk->prev = cur;
	while (cur)
	{
		if ((cur->use == 0) && (cur == main_uk->gnext))
		{
			main_uk->prev = cur->next;
			free_way_down(cur);
			cur = main_uk->prev;
			main_uk->gnext = cur;
		}
		else if (cur->use == 0)
		{
			main_uk->prev->next = cur->next;
			free_way_down(cur);
			cur = main_uk->prev->next;
		}
		else
		{
			main_uk->prev = cur;
			cur = cur->next;
		}
	}
}

/*
*** count nb of steps in way
*/

int			count_steps(t_gps *cur)
{
	t_way	*start;
	int		count;

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

int			count_nbbor(t_ngbor *uk)
{
	int		res;

	res = 0;
	while (uk)
	{
		res++;
		uk = uk->next;
	}
	return (res);
}
