/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:50:54 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 19:50:55 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** change node with start
*/

void	change_start(t_rooms **alst)
{
	t_rooms *cur;
	t_rooms *prev;

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

void algo(t_rooms *alst)
{
	while (t)
}