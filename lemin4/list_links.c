/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:24:46 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 11:24:47 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** check correct name of links with name of room in nodes
*/

int				check_links(t_rooms *alst, char **res)
{
	t_rooms		*tmp;
	int			count;

	count = 0;
	tmp = alst;
	while (tmp)
	{
		if (ft_strequ(tmp->room, res[0]))
			count++;
		if (ft_strequ(tmp->room, res[1]))
			count++;
		tmp = tmp->next;
	}
	if (count == 2)
		return (0);
	return (1);
}

/*
*** create new node of ngbor
*/

t_ngbor			*ft_lstnb_new(char *name)
{
	t_ngbor		*tmp;

	if ((tmp = ft_memalloc(sizeof(t_ngbor))) == NULL)
		return (NULL);
	tmp->ngbor = name;
	tmp->next = NULL;
	return (tmp);
}

/*
*** push ngbor node to the rooms node
*/

void			lstnb_pback(t_ngbor **alst, t_ngbor *new)
{
	t_ngbor		*beg;

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
*** return ngbor start node of correct rooms node
*/

t_ngbor			**ft_srch_beg_nb(t_rooms **alst, char *a)
{
	t_rooms		*beg;

	beg = (*alst);
	while (beg)
	{
		if (ft_strequ(beg->room, a))
			return (&(beg->down));
		beg = beg->next;
	}
	return (&beg->down);
}

/*
*** change node with start
*/

void			change_start(t_rooms **alst)
{
	t_rooms		*cur;
	t_rooms		*prev;

	cur = (*alst);
	if (cur->position == 1 && cur == (*alst))
		return ;
	while (cur)
	{
		if (cur->position == 1)
		{
			prev->next = cur->next;
			cur->next = (*alst);
			(*alst) = cur;
		}
		prev = cur;
		cur = cur->next;
	}
}
