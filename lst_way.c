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

t_gps		*lst_gps(t_way *start)
{
	t_gps	*tmp;

	if ((tmp = ft_memalloc(sizeof(t_gps))) == NULL)
		return (NULL);
	tmp->uk_way = start;
	tmp->next = NULL;
	return (tmp);
}

void		lst_gps_pb(t_gps **alst, t_gps *new)
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

t_way		*lst_way(t_rooms *ukaz)
{
	t_way	*tmp;

	if ((tmp = ft_memalloc(sizeof(t_way))) == NULL)
		return (NULL);
	tmp->ukaz = ukaz;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/*
*** add new node of way back
*/

void		lst_way_pb(t_way **alst, t_way *new)
{
	t_way	*beg;

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

void		lst_way_copy(t_way **dst, t_way *src)
{
	t_way	*src_beg;

	src_beg = src;
	while (src_beg)
	{
		lst_way_pb(dst, lst_way(src_beg->ukaz));
		src_beg = src_beg->next;
	}
}
