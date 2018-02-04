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

/*
*** create new node of way list
*/

t_way	*lst_way(char *name)
{
	t_way *tmp;

	if ((tmp = ft_memalloc(sizeof(t_way))) == NULL)
		return (NULL);
	tmp->name = name;
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
*** return ngbor node with equale name_room
*/

// t_ngbor			*ft_srch_back_nb(t_rooms **alst, char *a)
// {
// 	t_rooms		*beg;

// 	beg = (*alst);
// 	while (beg)
// 	{
// 		if (ft_strequ(beg->room, a))
// 			return ((beg->down));
// 		beg = beg->next;
// 	}
// 	return (beg->down);
// }


/*
*** return rooms node with equale name_ngbor
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






