/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:17:27 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/09 09:17:28 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_prev_sway(t_all_data *main_uk)
{
	t_gps *start;
	t_way *cur;
	t_way *last;

	start = main_uk->gnext;
	while (start)
	{
		last = NULL;
		cur = start->uk_way;
		while (cur)
		{
			cur->prev = last;
			last = cur;
			cur = cur->next;
		}
		start = start->next;
	}
}

int		ft_end(t_all_data *main_uk)
{
	t_gps *start;
	t_way *cur;

	start = main_uk->gnext;
	while (start)
	{
		cur = start->uk_way->next;
		while (cur)
		{
			if (cur->id != 0)
				return (1);
			cur = cur->next;
		}
		start = start->next;
	}
	return (0);
}

/*
*** find min positions of 
*/

void	fill_way_possible(t_all_data *main_uk)
{
	int res;

	int count = 1;
	res = 0;
	t_gps *start;
	start = main_uk->gnext;
	while (start)
	{
		res += start->steps;
		start->use = (count * start->steps) - res;
		start = start->next;
		++count;
	}
}
void	ft_print_ant(t_all_data *main_uk)
{
	fill_prev_sway(main_uk);
	fill_way_possible(main_uk);

	
	t_way	*start;
	t_way	*end;
	t_gps	*cur;
	uint32_t	ants;
	uint8_t		costil = 0;
	ants = 0;
	cur = main_uk->gnext;
	while (1)
	{
		start = cur->uk_way;
		while (start->next)
			start = start->next;
		end = start;
		while (start->ukaz->position != 1)
		{
			if (start->prev->ukaz->position != 1)
				start->id = start->prev->id;
			else
				start->id = ++ants <= main_uk->nb_ants ? ants : 0;
			start = start->prev;
		}
		start = end;
		if (!(ft_end(main_uk)))
			break ;
		while (start->prev)
		{
			if (start->id != 0)
			{
				if (costil == 1)
					printf(" ");
				costil = 1;
				printf("L%u-%s", start->id, start->ukaz->room);
			}
			start = start->prev;
			if (start->prev == NULL)
				costil = 0;
		}
		printf("\n");
	}
//	printf("\n");
}
