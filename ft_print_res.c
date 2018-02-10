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

int			ft_end(t_all_data *main_uk)
{
	t_gps	*start;
	t_way	*cur;

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
*** find min positions of ways ants
*/

void		fill_way_possible(t_all_data *main_uk)
{
	int		res;
	int		count;
	t_gps	*start;

	count = 1;
	res = 0;
	start = main_uk->gnext;
	while (start)
	{
		res += start->steps;
		start->use = (count * start->steps) - res;
		start = start->next;
		++count;
	}
}

void		go_ant(t_all_data *main_uk, int *ants)
{
	t_way	*start;
	t_gps	*cur;

	cur = main_uk->gnext;
	while (cur)
	{
		*ants += 1;
		start = cur->uk_way;
		while (start->next)
			start = start->next;
		while (start->ukaz->position != 1)
		{
			if (start->prev->ukaz->position != 1)
				start->id = start->prev->id;
			else
				start->id = (cur->use <= (main_uk->nb_ants - *ants)) ?
				*ants : 0;
			start = start->prev;
		}
		cur = cur->next;
	}
}

void		find_print_ants(t_all_data *main_uk)
{
	t_way	*start;
	t_gps	*cur;
	int		costil;

	costil = 0;
	cur = main_uk->gnext;
	while (cur)
	{
		start = cur->uk_way;
		while (start->next)
			start = start->next;
		while (start->prev)
		{
			if (start->id != 0)
			{
				if (costil == 1)
					ft_printf(" ");
				costil = 1;
				ft_printf("L%u-%s", start->id, start->ukaz->room);
			}
			start = start->prev;
		}
		cur = cur->next;
	}
	ft_printf("\n");
}

void		ft_print_ant(t_all_data *main_uk)
{
	t_gps	*cur;
	int32_t	ants;

	ants = 0;
	cur = main_uk->gnext;
	while (1)
	{
		go_ant(main_uk, &ants);
		if (!(ft_end(main_uk)))
			break ;
		find_print_ants(main_uk);
	}
}
