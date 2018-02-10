/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:00:12 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/10 15:00:13 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** print usage when the argv[1] == --help
*/

static void	ft_logo(void)
{
	int		fd;
	char	*help;
	char	*a;

	a = "\x1b[33m\n\n\n";
	write(1, a, ft_strlen(a));
	fd = open("logo", O_RDONLY);
	while (get_next_line(fd, &help))
	{
		write(1, help, ft_strlen(help));
		write(1, "\n", 1);
		free(help);
	}
	close(fd);
}

static void	ft_unit(void)
{
	int		fd;
	char	*help;
	char	*a;

	a = "\x1b[34m\n\n\n";
	write(1, a, ft_strlen(a));
	fd = open("unit_name", O_RDONLY);
	while (get_next_line(fd, &help))
	{
		write(1, help, ft_strlen(help));
		write(1, "\n", 1);
		free(help);
	}
	close(fd);
}

static void	ft_usage(void)
{
	int		fd;
	char	*help;
	char	*a;

	a = "\x1b[39m\n\n\n";
	write(1, a, ft_strlen(a));
	fd = open("help", O_RDONLY);
	while (get_next_line(fd, &help))
	{
		write(1, help, ft_strlen(help));
		write(1, "\n", 1);
		free(help);
	}
	close(fd);
}

void		ft_help(char **av)
{
	if (ft_strequ("--help", av[1]))
	{
		ft_logo();
		ft_unit();
		ft_usage();
		exit(0);
	}
}
