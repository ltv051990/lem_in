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

void	ft_lemin(t_all_data *main_uk)
{
	ft_read_data(main_uk);
	if (check_start_end_nb(&(main_uk->rnext), 1) == 0)
		ft_error("Start doesn't have links");
	if (check_start_end_nb(&(main_uk->rnext), 2) == 0)
		ft_error("End doesn't have links");
	change_start(&main_uk->rnext);
	algo(main_uk);
	if (main_uk->fl == 0)
		ft_error("No way from start to end");
	sort_stack(main_uk);
}

void ft_print(t_all_data *main_uk)
{
	t_list_map *tmp = NULL;
	t_rooms *b = NULL;
	t_ngbor *q = NULL;
	t_gps *gps = NULL;
	t_way *way = NULL;

	gps = main_uk->gnext;
//	write(1, "\n\n", 2);
	while (gps)
	{
		printf("%d\n", gps->fn);
		way = gps->uk_way;
		while (way)
		{
			printf("main way %s\n", way->ukaz->room);
			way = way->next;
		}
		printf("\n");
		gps = gps->next;
	}	


	b = main_uk->rnext;
	write(1, "\n\n", 2);
	while (b)
	{
		q = b->down;
		printf("\nroom %s susidu = ", b->room);
		while (q)
		{
			printf(" %s ", q->ngbor);
			q = q->next;
		}
		b = b->next;
	}
	// tmp = main_uk->mnext;
	b = main_uk->rnext;
	// while (tmp)
	// {
	//  	write(1, "\n", 1);
	//  	write(1, tmp->content, ft_strlen(tmp->content));
	//  	tmp = tmp->next;
	// }
	// write(1, "\n", 1);
	printf("\n");
	while (b)
	{
		printf("%-6s rooms position %hhd empty %hhd y %s x %s\n", b->room, b->position, b->empty, b->y_cord, b->x_cord);
	  	b = b->next;
	}
	printf("\n");

	// q = main_uk->rnext->next->down;
	// while (q)
	// {
	// 	printf("%s\n", q->ngbor);
	// 	q = q->next;

	// }
}

int main(int argc, char **argv)
{
	t_all_data *main_uk;

	if (argc == 2)
		ft_help(argv[1]);
	main_uk = ft_memalloc(sizeof(t_all_data));
	ft_defolt_struct(main_uk);
	ft_lemin(main_uk);

	ft_print(main_uk);
	system("leaks lem-in");
	return (0);
}
