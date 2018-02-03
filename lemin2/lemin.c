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
}

void ft_help(char *av)
{
	int fd;
	char *help;
	char *a;

	if (ft_strequ("--help", av))
	{
		fd = open("help", O_RDONLY);
		while (get_next_line(fd, &help))
		{
			printf("%s\n", help);
			free(help);
		}
		a = ft_strjoin("\x1b[33m", "To be continued...\n");
		write(1, a, ft_strlen(a));
		ft_strdel(&a);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_help(argv[1]);
	t_all_data *main_uk;
	t_list_map *tmp = NULL;
	t_rooms *b = NULL;
	t_ngbor *q = NULL;

	main_uk = ft_memalloc(sizeof(t_all_data));
	ft_defolt_struct(main_uk);
	ft_lemin(main_uk);
	//////////////////////////////////////////////////////////////////////////////
	
	b = main_uk->rnext;
	write(1, "\n\n", 2);
	while (b)
	{
		q = b->down;
		while (q)
		{
			printf("%s ", q->ngbor);
			q = q->next;
		}
		printf("\n");
		b = b->next;
	}
	//////////////////////////////////////////////////////////////////////////////
	write(1, "\n", 1);
	tmp = main_uk->mnext;
	b = main_uk->rnext;

	while (tmp)
	{
	 	write(1, "\n", 1);
	 	write(1, tmp->content, ft_strlen(tmp->content));
	 	tmp = tmp->next;
	}
	write(1, "\n", 1);
	while (b)
	{
		printf("%-6s position rooms %hhd empty %hhd y %s x %s\n", b->room, b->position, b->empty, b->y_cord, b->x_cord);
	  	b = b->next;
	}


	q = main_uk->rnext->next->down;
	while (q)
	{
		printf("%s\n", q->ngbor);
		q = q->next;
	}
	system("leaks lem-in < example");
	return (0);
}
