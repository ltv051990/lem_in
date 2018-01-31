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
*** check nb of ant
*/

void	ft_check_nb_ants(t_all_data *main_uk, char **line)
{
	int index;

	index = 0;

	if (**line == '0')
		ft_error("INCORECT NB ANTS");
	if (ft_isdigit(**line))
		main_uk->nb_ants = ft_atoi(*line);
	else
		ft_error("INCORECT NB ANTS");
	while (ft_isdigit((*line)[index]))
		index++;
	if ((*line)[index] != '\0' || main_uk->nb_ants <= 0)
		ft_error("INCORECT NB ANTS");
	main_uk->fl_ants = 1;
	ft_listmap_push_back(&main_uk->mnext, ft_lstmap_new(*line));	
}

int check_space(char *line)
{
	int res;

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

int 	ft_check_cord(char **res)
{
	char	*check;

	check = res[1];
	while(ft_isdigit(*check))
		check++;
	if (*check != '\0')
		return (0);
	check = res[2];
	while(ft_isdigit(*check))
		check++;
	if (*check != '\0')
		return (0);
	return (1);
}

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
	if (!ft_check_cord(res))
		ft_error("BAD CORDINATES");
	if (flags == 1)
	 	ft_listroom_push_back(&main_uk->rnext, ft_lstroom_new(res[0], 1));
	if (flags == 2)
	 	ft_listroom_push_back(&main_uk->rnext, ft_lstroom_new(res[0], 2));
	if (flags == 0)
	 	ft_listroom_push_back(&main_uk->rnext, ft_lstroom_new(res[0], 0));
	free(res[1]);
	free(res[2]);
	free(res);
}

void	check_rooms(t_all_data *main_uk, char *line)
{
	int a = 0;
	if (*line == ' ')
		ft_error("STRING CAN'T START WIHT THE SPACE");
	if (*line == 'L')
		ft_error("L CAN'T BE FIRST LETTER IN STRING");
	if (ft_strchr(line, ' '))
		split_room(main_uk, line, 0);		
	else
	{
		main_uk->cor_input = 0;
	}
}