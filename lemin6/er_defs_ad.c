/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_defs_ad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:55:24 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/03 11:55:26 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** print error and exit program
*/

void		ft_error(char *s)
{
	char	*a;

	a = ft_strjoin("\x1b[31m", "ERROR\n");
	write(1, a, ft_strlen(a));
	ft_strdel(&a);
	a = ft_strjoin("\x1b[33m", s);
	write(1, a, ft_strlen(a));
	ft_strdel(&a);
	write(1, "\n", 1);
	exit(0);
}

/*
*** delete split res before exit prigram
*/

int			del_spl(char **res, int s)
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
*** def struct when program start
*/

void		ft_defolt_struct(t_all_data *main_uk)
{
	main_uk->fl_ants = 0;
	main_uk->fl_rooms = 0;
	main_uk->fl_lines = 0;
	main_uk->fl_end = 0;
	main_uk->fl_start = 0;
	main_uk->cor_input = 1;
	main_uk->cor_lines = 1;
}

/*
*** print usage when the argv[1] == --help
*/

void		ft_help(char *av)
{
	int		fd;
	char	*help;
	char	*a;

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
