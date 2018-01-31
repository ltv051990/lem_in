/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:41 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/28 16:02:42 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void	ft_check_nb_ants(t_all_data *main_uk, char **line)
{
	int index;

	index = 0;
	if (get_next_line(0, line) == 0)
		ft_error();
	else
	{	
		if (**line == '0')
			ft_error();
		if (ft_isdigit(**line))
			main_uk->nb_ants = ft_atoi(*line);
		else
			ft_error();
	}
	while (ft_isdigit((*line)[index]))
		index++;
	if ((*line)[index] != '\0' || main_uk->nb_ants <= 0)
		ft_error();
}

int		check_start_end(char *line, char *compare)
{
	if (ft_strlen(line) != ft_strlen(compare))
		return (1);
	return (0);
}

void	ft_read_data(t_all_data *main_uk, t_list_map **start)
{
	char *line;

	while (get_next_line(0, &line))
	{
		ft_listmap_push_back(start, ft_lstmap_new(line));
		if (ft_strstr(line, "##"))
		{
			if (ft_strstr(line, "##end"))
			{
				if (check_start_end(line, "##end"))
					ft_error();
				main_uk->fl_start = 1;
			}
			else if (ft_strstr(line, "##start"))
			{
				if (check_start_end(line, "##start"))
					ft_error();
				main_uk->fl_end = 1;
			}
		}
	}
}
void	ft_lemin(t_all_data *main_uk, t_list_map **start)
{
	ft_read_data(main_uk, start);
}

int main(void)
{
	t_all_data main_uk;
	t_list_map *start = NULL;
	t_list_map *tmp = NULL;


	// main_uk.rnext = ft_memalloc(sizeof(t_rooms));
	// main_uk.cnext = ft_memalloc(sizeof(t_rcord));
	ft_lemin(&main_uk, &start);
	tmp = start;
	while (tmp)
	{
	 	printf("%s\n", tmp->content);
	 	tmp = tmp->next;
	}
	return (0);
}
