/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:42:43 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 15:42:45 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** first check when i see nb_ants
*/

void		rd_block_ant(t_all_data *main_uk, char **line)
{
	while (main_uk->fl_ants != 1)
	{
		if (get_next_line(0, line) == 0)
			ft_error("EMPTY INPUT");
		if (**line == '#')
		{
			if (ft_strequ(*line, "##end"))
				ft_error("INCORECT END");
			else if (ft_strequ(*line, "##start"))
				ft_error("INCORECT START");
			else if ((*line)[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
			else if ((*line)[1] == '#')
				ft_strdel(line);
		}
		else if (ft_isdigit(**line))
			ft_check_nb_ants(main_uk, line);
		else
			ft_error("INCORECT NB ANTS");
	}
}

/*
*** next check blocks rooms
*/

void		rd_block_rms(t_all_data *main_uk, char **line, int ret)
{
	ret = 1;
	while (ret && main_uk->cor_input)
	{
		if ((ret = get_next_line(0, line)) == 0)
			main_uk->cor_lines = 0;
		if (ret != 0 && **line == '#')
		{
			if (ft_strequ(*line, "##end"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
				check_end(main_uk, 1);
			}
			else if (ft_strequ(*line, "##start"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
				check_start(main_uk, 1);
			}
			else if ((*line)[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
			else if ((*line)[1] == '#')
				ft_strdel(line);
		}
		else if (ret != 0)
			check_rooms(main_uk, *line);
	}
}

/*
*** check lines
*/

void		rd_block_lnk(t_all_data *main_uk, char **line, int ret)
{
	ret = 1;
	while (main_uk->cor_lines)
	{
		if ((ret = get_next_line(0, line)) == 0)
			break ;
		if (**line == '#')
		{
			if (ft_strequ(*line, "##end"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
				ft_error("BAD END IN LINKS");
			}
			else if (ft_strequ(*line, "##start"))
			{
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
				ft_error("BAD START IN LINKS");
			}
			else if ((*line)[1] != '#')
				ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
			else if ((*line)[1] == '#')
				ft_strdel(line);
		}
		else
			check_lines(main_uk, *line);
	}
}

/*
*** next check rooms
*/

void		ft_read_data(t_all_data *main_uk)
{
	char	*line;
	int		ret;

	rd_block_ant(main_uk, &line);
	ret = 1;
	rd_block_rms(main_uk, &line, ret);
	if (main_uk->fl_start == 0)
		ft_error("No start!!!");
	if (main_uk->fl_end == 0)
		ft_error("No end!!!");
	rd_block_lnk(main_uk, &line, ret);
	if (main_uk->fl_lines == 0)
		ft_error("NO LINKS IN MAP");
}
