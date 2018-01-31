/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:08:46 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/31 23:08:46 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_start(t_all_data *main_uk, int flag)
{
	char *line;
	int ret;

	if (flag == 1)
		(main_uk->fl_start)++;
	if (main_uk->fl_start > 1)
		ft_error("TOO MANY START");
	if	((ret = get_next_line(0, &line) == 0) || ft_strequ(line, "##start")
		|| ft_strequ(line, "##end"))
		ft_error("INCORECT START");
	if (*line == '#' && line[1] != '#')
	{
		ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
		check_start(main_uk, 0);
		return ;
	}
	if (*line == '#' && line[1] == '#')
	{
		free(line);
		check_start(main_uk, 0);
		return ;
	}
	if (*line != '#')
		split_room(main_uk, line, 1);
}

void	check_end(t_all_data *main_uk, int flag)
{
	char *line;
	int ret;

	if (flag == 1)
		(main_uk->fl_end)++;
	if (main_uk->fl_end > 1)
		ft_error("TOO MANY END");
	if	((ret = get_next_line(0, &line) == 0) || ft_strequ(line, "##start")
		|| ft_strequ(line, "##end"))
		ft_error("INCORECT END");
	if (*line == '#' && line[1] != '#')
	{
		ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
		check_end(main_uk, 0);
		return ;
	}
	if (*line == '#' && line[1] == '#')
	{
		free(line);
		check_end(main_uk, 0);
		return ;
	}
	if (*line != '#')
		split_room(main_uk, line, 2);
}
