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

void		check_start(t_all_data *main_uk, int flag)
{
	char	*line;
	int		ret;

	if (flag == 1)
		(main_uk->fl_start)++;
	if (main_uk->fl_start > 1)
		ft_error("TOO MANY START");
	if ((ret = get_next_line(0, &line) == 0) || ft_strequ(line, "##start")
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

void		check_end(t_all_data *main_uk, int flag)
{
	char	*line;
	int		ret;

	if (flag == 1)
		(main_uk->fl_end)++;
	if (main_uk->fl_end > 1)
		ft_error("TOO MANY END");
	if ((ret = get_next_line(0, &line) == 0) || ft_strequ(line, "##start")
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

/*
*** check space in room
*/

int			check_space(char *line)
{
	int		res;

	res = 0;
	while (*line != 0)
	{
		if (*line == ' ')
			res++;
		line++;
	}
	if (res == 2)
		return (1);
	return (0);
}

/*
*** check nb of ant
*/

void		ft_check_nb_ants(t_all_data *main_uk, char **line)
{
	int		index;

	index = 0;
	if (**line == '0')
		ft_error("INCORECT NB ANTS");
	if (ft_isdigit(**line))
		main_uk->nb_ants = ft_atoi(*line);
	else
		ft_error("INCORECT NB ANTS");
	while (ft_isdigit((*line)[index]))
		index++;
	if ((*line)[index] != '\0' || main_uk->nb_ants <= 0 || index > 9)
		ft_error("INCORECT NB ANTS");
	main_uk->fl_ants = 1;
	ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));
}

/*
*** check cords in room
*/

int			ft_check_cord(char **res)
{
	char	*check;
	int		len;

	len = 0;
	check = res[1];
	while (ft_isdigit(check[len]))
		len++;
	if (check[len] != '\0' || len > 9)
		return (0);
	len = 0;
	check = res[2];
	while (ft_isdigit(check[len]))
		len++;
	if (check[len] != '\0' || len > 9)
		return (0);
	return (1);
}
