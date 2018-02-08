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

void	algo_check(t_all_data *main_uk)
{
	t_gps *cur;
	t_way *start;

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