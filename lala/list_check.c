/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:46:47 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 11:46:49 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** check correct nodes in rooms
*/

int				check_double_link(t_ngbor **alst, char *name)
{
	t_ngbor		*beg;

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
	t_ngbor		*beg;
	int			count;

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

int				check_start_end_nb(t_rooms **ast, int8_t position)
{
	t_rooms	*tmp;

	tmp = (*ast);
	while (tmp)
	{
		if (tmp->position == position)
			return (count_ngbor_st_end(tmp->down));
		tmp = tmp->next;
	}
	return (0);
}
