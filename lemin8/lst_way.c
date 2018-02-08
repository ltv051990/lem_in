/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:16:17 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/04 12:16:18 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_gps *lst_gps(t_way *start)
{
	t_gps *tmp;
	if ((tmp = ft_memalloc(sizeof(t_gps))) == NULL)
		return (NULL);
	tmp->uk_way = start;
	tmp->next = NULL;
	return (tmp);

}


void	lst_gps_pb(t_gps **alst, t_gps *new)
{
	t_gps	*beg;

	if (!alst)
		return ;
	else if (!(*alst))
		*alst = new;
	else
	{
		beg = *alst;
		while (beg->next)
			beg = beg->next;
		beg->next = new;
	}
}

/*
*** create new node of way list
*/

t_way	*lst_way(t_rooms *ukaz)
{
	t_way *tmp;

	if ((tmp = ft_memalloc(sizeof(t_way))) == NULL)
		return (NULL);
	tmp->ukaz = ukaz;
	tmp->next = NULL;
	return (tmp);
}

/*
*** add new node of way back
*/

void	lst_way_pb(t_way **alst, t_way *new)
{
	t_way		*beg;

	if (!alst)
		return ;
	else if (!(*alst))
		*alst = new;
	else
	{
		beg = *alst;
		while (beg->next)
			beg = beg->next;
		beg->next = new;
	}
}

/*
*** special functions that make new copy of current list
*** of nodes
*/

void	lst_way_copy(t_way **dst, t_way *src)
{
	t_way *src_beg;

	src_beg = src;
	while (src_beg)
	{
		lst_way_pb(dst, lst_way(src_beg->ukaz)); 
		src_beg = src_beg->next;
	}
}

/*
**
*/

t_rooms			*ft_srch_back_room(t_rooms **alst, char *a)
{
	t_rooms		*beg;

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
*** all check same room visit
*/

int		check_visit_all(t_rooms **alst)
{
	t_rooms *tmp;

	tmp = (*alst);
	while (tmp)
	{
		if (tmp->empty == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


int		check_visit_one(t_rooms **alst, char *a)
{
	t_rooms *tmp;

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
*** return rooms after check visits
*** return NULL when all rooms were visitid
*** and we don't have next ngbor
*/

t_rooms *next_room(t_rooms **start, t_rooms *cur)
{
	t_ngbor *tmp;

	tmp = cur->down;
	while (tmp)
	{
		if (check_visit_one(start, tmp->ngbor))
			return (ft_srch_back_room(start, tmp->ngbor));
		tmp = tmp->next;
	}
	return (NULL);
}

/*
*** check correct name of links with name of room in nodes
*/
