/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_doble_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:14:07 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/08 10:14:09 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** check mistake gps->fn in stack
*/

void		algo_check(t_all_data *main_uk)
{
	t_gps	*cur;
	t_way	*start;

	cur = main_uk->gnext;
	while (cur)
	{
		start = cur->uk_way;
		while (start->next)
			start = start->next;
		if (start->ukaz->position == 2)
		{
			cur->fn = 1;
			main_uk->fl += 1;
		}
		cur = cur->next;
	}
}

int			check_visit_one(t_rooms **alst, char *a)
{
	t_rooms	*tmp;

	tmp = (*alst);
	while (tmp)
	{
		if (ft_strequ(tmp->room, a))
		{
			if (tmp->empty == 0)
				return (1);
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
*** all check same room visit
*/

int			check_visit_all(t_rooms **alst)
{
	t_rooms	*tmp;

	tmp = (*alst);
	while (tmp)
	{
		if (tmp->empty == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
*** check correct name of links with name of room in nodes
*/

t_rooms		*ft_srch_back_room(t_rooms **alst, char *a)
{
	t_rooms	*beg;

	beg = (*alst);
	while (beg)
	{
		if (ft_strequ(beg->room, a))
			return ((beg));
		beg = beg->next;
	}
	return (beg);
}

/*
*** return rooms after check visits
*** return NULL when all rooms were visitid
*** and we don't have next ngbor
*/

t_rooms		*next_room(t_rooms **start, t_rooms *cur)
{
	t_ngbor	*tmp;

	tmp = cur->down;
	while (tmp)
	{
		if (check_visit_one(start, tmp->ngbor))
			return (ft_srch_back_room(start, tmp->ngbor));
		tmp = tmp->next;
	}
	return (NULL);
}
