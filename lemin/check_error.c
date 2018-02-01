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
*** print error and exit program 
*/

void	ft_error(char *s)
{
	write(1, "ERROR\n", 6);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(0);
}

/*
*** delete split res before exit prigram
*/

int		del_spl(char **res, int s)
{
	--s;
	while (s >= 0)
	{
		free((res[s]));
		s--;
	}
	free(res);
	return (1);
}

/*
*** first check valid name in room and call split func
*/

void	split_room(t_all_data *main_uk, char *line, int8_t flags)
{
	char **res;
	int s;

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
	 	ft_listroom_push_back(&main_uk->rnext, ft_lstroom_new(res[0], res[1], res[2], 1));
	else if  (flags == 2)
	 	ft_listroom_push_back(&main_uk->rnext, ft_lstroom_new(res[0], res[1], res[2], 2));
	else if (flags == 0)
	 	ft_listroom_push_back(&main_uk->rnext, ft_lstroom_new(res[0], res[1], res[2], 0));
	free(res);
}

/*
*** check minus in links
*/

int check_minus(char *line)
{
	int res;

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

void	split_links(t_all_data *main_uk, char *line)
{
	char **res;
	int s;

	res = NULL;
	s = 0;
	if ((check_minus(line)) != 1)
		ft_error("NOT CORRECT COUNT OF SPACE IN LINES");
	if (((s = ft_split_cw(line, '-', &res)) != 2) && (del_spl(res, s)))
		ft_error("INCORRECT NB OF ARGUMENTS IN LINES");
	ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(line));

}

/*
*** check rooms and write to struct
*/

void	check_rooms(t_all_data *main_uk, char *line)
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

void	check_lines(t_all_data *main_uk, char *line)
{
	printf("%s\n", "lala");
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






