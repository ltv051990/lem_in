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

/*
*** create new node for print map
*/

t_list_map		*ft_lstmap_new(char *content)
{
	t_list_map	*tmp;

	if ((tmp = (t_list_map *)malloc(sizeof(t_list_map))) == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

/*
*** add map node to back
*/

void			ft_listmap_push_back(t_list_map **alst, t_list_map *new)
{
	t_list_map	*beg;

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

/*
*** create new new node with room data
*/

t_rooms			*ft_lstroom_new(char *content, char *y_cord,
							char *x_cord, int8_t pos)
{
	t_rooms		*tmp;

	if ((tmp = ft_memalloc(sizeof(t_rooms))) == NULL)
		return (NULL);
	tmp->room = content;
	tmp->y_cord = y_cord;
	tmp->x_cord = x_cord;
	tmp->position = pos;
	tmp->empty = 0;
	return (tmp);
}

/*
*** add room node to back
*/

void			lstrm_pb(t_rooms **alst, t_rooms *new)
{
	t_rooms		*beg;

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

/*
*** check same nameofroom and cord of room
*/

int				check_same_r_c(t_rooms **alst, char **res)
{
	t_rooms		*tmp;

	tmp = *alst;
	while (tmp)
	{
		if (ft_strequ(tmp->room, res[0]))
			return (-1);
		if (ft_strequ(tmp->y_cord, res[1]) && ft_strequ(tmp->x_cord, res[2]))
			return (-2);
		tmp = tmp->next;
	}
	return (1);
}
