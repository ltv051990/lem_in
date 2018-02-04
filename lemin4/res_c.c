/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:55:52 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 12:55:53 by tlutsyk          ###   ########.fr       */
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
 	if (main_uk->fl_start == 0 || main_uk->fl_end == 0)
 		ft_error("start??? != end???");
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
			else
				check_lines(main_uk, line);
	}
 	if (main_uk->fl_start == 0 || main_uk->fl_end == 0 || main_uk->fl_lines == 0)
 		ft_error("NOT FULL INPUT");
}