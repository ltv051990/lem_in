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

void	ft_read_data(t_all_data *main_uk)
{
	char *line;
/*
*** first check when i see nb_ants 
*/
	while (main_uk->fl_ants != 1)
	{
		if (get_next_line(0, &line) == 0)
			ft_error("EMPTY INPUT");
		if (*line == '#')
		{
			if (ft_strequ(line, "##end"))
					ft_error("INCORECT END");
			else if (ft_strequ(line, "##start"))
				ft_error("INCORECT START");
			else if (line[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			else if (line[1] == '#')
				ft_strdel(&line);
		}
		else if (ft_isdigit(*line))
			ft_check_nb_ants(main_uk, &line);
		else
			ft_error("INCORECT NB ANTS");
	}
/*
*** first check when i see nb_ants
*/

/*
*** next check rooms
*/

	int ret = 1;
	while (ret && main_uk->cor_input)
	{
		if ((ret = get_next_line(0, &line)) == 0)
			main_uk->cor_lines = 0;
		if (ret != 0 && *line == '#')
		{
			if (ft_strequ(line, "##end"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				check_end(main_uk, 1);
			}
			else if (ft_strequ(line, "##start"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				check_start(main_uk, 1);
			}
			else if (line[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			else if (line[1] == '#')
				ft_strdel(&line);
		}
		else if (ret != 0)
			check_rooms(main_uk, line);
 	}
 
/*
*** check lines
*/
	ret = 1;
	while (main_uk->cor_lines)
	{
		if ((ret = get_next_line(0, &line)) == 0)
			break ;
		if (*line == '#')
		{
			if (ft_strequ(line, "##end"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				ft_error("BAD END IN LINKS");
			}
			else if (ft_strequ(line, "##start"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
				ft_error("BAD START IN LINKS");
			}
			else if (line[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			else if (line[1] == '#')
				ft_strdel(&line);
			}
			check_lines(main_uk, line);
	}
 	if (main_uk->fl_start == 0 || main_uk->fl_end == 0 || main_uk->fl_lines == 0)
 		ft_error("NOT FULL INPUT");
}

/*
*** next check rooms
*/

void	ft_lemin(t_all_data *main_uk)
{
	ft_read_data(main_uk);
	if (check_start_end_nb(&(main_uk->rnext), 1) == 0)
		ft_error("Start doesn't have links");
	if (check_start_end_nb(&(main_uk->rnext), 2) == 0)
		ft_error("End doesn't have links");
}

void	ft_defolt_struct(t_all_data *main_uk)
{
	main_uk->fl_ants = 0;
	main_uk->fl_rooms = 0;
	main_uk->fl_lines = 0;
	main_uk->fl_end = 0;
	main_uk->fl_start = 0;
	main_uk->cor_input = 1;
	main_uk->cor_lines = 1;
}

int main(void)
{
	t_all_data *main_uk;
	t_list_map *tmp = NULL;
	t_rooms *b = NULL;
	t_ngbor *q = NULL;

	main_uk = ft_memalloc(sizeof(t_all_data));
	ft_defolt_struct(main_uk);
	ft_lemin(main_uk);
	//////////////////////////////////////////////////////////////////////////////
	
	b = main_uk->rnext;
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
