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

t_list_map	*ft_lstmap_new(char	*content)
{
	t_list_map *tmp;

	if ((tmp = (t_list_map *)malloc(sizeof(t_list_map))) == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

/*
*** add map node to back
*/

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

/*
*** create new new node with room data
*/

t_rooms		*ft_lstroom_new(char *content, char *y_cord, char *x_cord, int8_t pos)
{
	t_rooms *tmp;

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

/*
*** check same nameofroom and cord of room
*/

int 	check_same_r_c(t_rooms **alst, char **res)
{
	t_rooms *tmp;

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

/*
*** check correct name of links with name of room in nodes
*/

int 	check_links(t_rooms *alst, char **res)
{
	t_rooms	*tmp;
	int		count;

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

t_ngbor		*ft_lstnb_new(char *name)
{
	t_ngbor *tmp;

//	printf("%s\n", "I am here ft_lstnb_new");
	if ((tmp = ft_memalloc(sizeof(t_ngbor))) == NULL)
		return (NULL);
	tmp->ngbor = name;
	tmp->next = NULL;
	return (tmp);
}

/*
*** push ngbor node to the rooms node
*/

void		ft_listnb_push_back(t_ngbor **alst, t_ngbor *new)
{
	t_ngbor *beg;

//	printf("%s\n", "I am here ft_listnb_push_back");
	if(!alst)
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
*** return start node of  correct node
*/

t_ngbor		**ft_srch_beg_nb(t_rooms **alst, char *a)
{
	t_rooms *beg;

//	printf("%s\n", "I am here ft_srch_beg_nb");
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
*** check correct nodes in 
*/

int 	check_double_link(t_ngbor **alst, char *name)
{
	t_ngbor *beg;

	beg = (*alst);
	while (beg)
	{
		if (ft_strequ(beg->ngbor, name))
			return (1);
		beg = beg->next;
	}
	return (0);
}

/*
*** count ngbor in start or end in ngbor 
*/

static int		count_ngbor_st_end(t_ngbor *alst)
{
	t_ngbor	*beg;
	int		count;

	count = 0;
	beg = alst;
	while (beg)
	{
		count++;
		beg = beg->next;
	}
	return (count);
}

/*
*** check ngbor in start or ngbor in ngbor 
*/

int 	check_start_end_nb(t_rooms **ast, int8_t position)
{
	t_rooms *tmp;

	tmp = (*ast);
	while (tmp)
	{
		if (tmp->position == position)
			return (count_ngbor_st_end(tmp->down));
		tmp = tmp->next;
	}
	return (0);
}












