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
		ret = get_next_line(0, &line);
		if (*line == '#')
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
		else
		{
			printf("%s\n", "yoyo");
			ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
			check_rooms(main_uk, line);
		}
 	}
 	//function must check all correct data and only then start to read
}

/*
*** next check rooms
*/

void	ft_lemin(t_all_data *main_uk)
{
	ft_read_data(main_uk);
}

void	ft_defolt_struct(t_all_data *main_uk)
{
	main_uk->fl_ants = 0;
	main_uk->fl_rooms = 0;
	main_uk->fl_lines = 0;
	main_uk->fl_end = 0;
	main_uk->fl_start = 0;
	main_uk->cor_input = 1;
}

int main(void)
{
	t_all_data main_uk;
	t_list_map *tmp = NULL;
	t_rooms *b = NULL;

	ft_defolt_struct(&main_uk);
	ft_lemin(&main_uk);
	tmp = main_uk.mnext;
	b = main_uk.rnext;
	// while (tmp)
	// {
	//  	printf("%s\n", tmp->content);
	//  	tmp = tmp->next;
	// }
	b = b->next;
	while (b)
	{
		printf("%-6s position rooms %hhd empty %hhd\n", b->room, b->position, b->empty);
	  	b = b->next;
	}
	system("leaks lem-in < example");
	return (0);
}
