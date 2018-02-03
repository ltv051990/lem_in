/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:17:40 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/30 11:17:41 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** first check valid name in room and call split func
*/

void		split_room(t_all_data *main_uk, char *line, int8_t flags)
{
	char	**res;
	int		s;

	res = NULL;
	s = 0;
	ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
	if (*line == 'L')
		ft_error("L CAN'T BE FIRST LETTER IN ROOM NAME");
	if (!(check_space(line)))
		ft_error("NOT CORRECT COUNT OF SPACE IN ROOM");
	if (((s = ft_split_cw(line, ' ', &res)) != 3) && (del_spl(res, s)))
		ft_error("INCORRECT NB OF ARGUMENTS IN ROOM");
	if (!ft_check_cord(res) && (del_spl(res, s)))
		ft_error("BAD CORDINATES");
	if (((s = check_same_r_c(&main_uk->rnext, res)) < 0))
		ft_error(s == -1 ? "SAME ROOM NAME WAS UP" : "SAME ROOM CORD WERE UP");
	if (flags == 1)
		lstrm_pb(&main_uk->rnext, ft_lstroom_new(res[0], res[1], res[2], 1));
	else if (flags == 2)
		lstrm_pb(&main_uk->rnext, ft_lstroom_new(res[0], res[1], res[2], 2));
	else if (flags == 0)
		lstrm_pb(&main_uk->rnext, ft_lstroom_new(res[0], res[1], res[2], 0));
	free(res);
}

/*
*** check minus in links
*/

int			check_minus(char *line)
{
	int		res;

	res = 0;
	while (*line != 0)
	{
		if (*line == '-')
			res++;
		line++;
	}
	if (res == 1)
		return (1);
	return (0);
}

void		split_links(t_all_data *main_uk, char *line)
{
	char	**res;
	int		s;

	res = NULL;
	s = 0;
	ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));
	if ((check_minus(line)) != 1)
		ft_error("NOT CORRECT COUNT OF SPACE IN LINES");
	if (((s = ft_split_cw(line, '-', &res)) != 2) && (del_spl(res, s)))
		ft_error("INCORRECT NB OF ARGUMENTS IN LINES");
	if (ft_strequ(res[0], res[1]) && (del_spl(res, s)))
		ft_error("Same rooms name in links");
	if (check_links(main_uk->rnext, res) && (del_spl(res, s)))
		ft_error("BAD LINKS");
	if (check_double_link(ft_srch_beg_nb(&main_uk->rnext, res[0]), res[1]))
		ft_error("SAME LINKS");
	++(main_uk->fl_lines);
	lstnb_pback(ft_srch_beg_nb(&main_uk->rnext, res[0]), ft_lstnb_new(res[1]));
	lstnb_pback(ft_srch_beg_nb(&main_uk->rnext, res[1]), ft_lstnb_new(res[0]));
	free(res);
}

/*
*** check rooms and write to struct
*/

void		check_rooms(t_all_data *main_uk, char *line)
{
	if (*line == ' ')
		ft_error("STRING CAN'T START WIHT THE SPACE");
	if (*line == 'L')
		ft_error("L CAN'T BE FIRST LETTER IN STRING");
	if (ft_strchr(line, ' '))
		split_room(main_uk, line, 0);
	else
	{
		main_uk->cor_input = 0;
		check_lines(main_uk, line);
	}
}

/*
*** check lines and write to struct
*/

void		check_lines(t_all_data *main_uk, char *line)
{
	if (*line == ' ')
		ft_error("STRING CAN'T START WIHT THE SPACE");
	if (*line == 'L')
		ft_error("L CAN'T BE FIRST LETTER IN STRING");
	if (ft_strchr(line, '-'))
		split_links(main_uk, line);
	else
	{
		free(line);
		main_uk->cor_lines = 0;
	}
}
