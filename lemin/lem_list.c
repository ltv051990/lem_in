/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:43:13 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/28 18:43:14 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_map	*ft_lstmap_new(char	*content)
{
	t_list_map *tmp;

	if ((tmp = (t_list_map *)malloc(sizeof(t_list_map))) == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

void	ft_listmap_push_back(t_list_map **alst, t_list_map *new)
{
	t_list_map *beg;

	if (!alst)
		return ;
	else if (!(*alst))
		(*alst) = new;
	else
	{
		beg = (*alst);
		while (beg->next)
			beg = beg->next;
		beg->next = new;
	}
}

t_rooms		*ft_lstroom_new(char *content, int8_t pos)
{
	t_rooms *tmp;

	if ((tmp = ft_memalloc(sizeof(t_rooms))) == NULL)
		return (NULL);
	tmp->room = content;
	tmp->position = pos;
	tmp->empty = 0;
	return (tmp);
}

void	ft_listroom_push_back(t_rooms **alst, t_rooms *new)
{
	t_rooms *beg;

	if (!alst)
		return ;
	else if (!(*alst))
		(*alst) = new;
	else
	{
		beg = (*alst);
		while (beg->next)
			beg = beg->next;
		beg->next = new;
	}
}
