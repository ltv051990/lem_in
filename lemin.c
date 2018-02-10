/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:48:28 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/26 18:48:29 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** check block
*/

void			ft_lemin(t_all_data *main_uk)
{
	ft_read_data(main_uk);
	if (check_start_end_nb(&(main_uk->rnext), 1) == 0)
		ft_error("Start doesn't have links", main_uk);
	if (check_start_end_nb(&(main_uk->rnext), 2) == 0)
		ft_error("End doesn't have links", main_uk);
	change_start(&main_uk->rnext);
	algo(main_uk);
	algo_check(main_uk);
	if (main_uk->fl == 0)
		ft_error("No way from start to end", main_uk);
	sort_stack(main_uk);
}

void			ft_print_map(t_all_data *main_uk)
{
	t_list_map	*tmp;
	t_rooms		*b;
	t_gps		*gps;

	tmp = NULL;
	b = NULL;
	gps = NULL;
	gps = main_uk->gnext;
	tmp = main_uk->mnext;
	b = main_uk->rnext;
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void			ft_print_way(t_all_data *main_uk)
{
	t_gps		*start;
	t_way		*cur;

	ft_printf("\n");
	start = main_uk->gnext;
	while (start)
	{
		cur = start->uk_way;
		while (cur)
		{
			ft_printf("-> { %s }", cur->ukaz->room);
			cur = cur->next;
		}
		start = start->next;
		ft_printf("\n");
	}
	ft_printf("\n");
}

int				main(int argc, char **argv)
{
	t_all_data	*main_uk;

	if (argc > 1)
		ft_help(argv);
	main_uk = ft_memalloc(sizeof(t_all_data));
	ft_defolt_struct_lem(main_uk);
	if (argc > 1)
		ft_bonus(main_uk, argv, argc);
	ft_lemin(main_uk);
	write(1, "\n", 1);
	ft_print_map(main_uk);
	fill_prev_sway(main_uk);
	fill_way_possible(main_uk);
	if (main_uk->prw)
		ft_print_way(main_uk);
	ft_print_ant(main_uk);
	return (0);
}
