/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:18:21 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/07 17:18:22 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** check block
*/

void	free_way_down(t_way *down)
{
	t_way *res;

	while (down)
	{
		res = down;
		down = down->next;
		free(res);
	}
}

void	sort_stack(t_all_data *main_uk)
{
	t_gps **start;
	t_gps *tmp1;
	t_gps *tmp2;

	start = &(main_uk->gnext);
	tmp1 = *start;
	while(tmp1)
	{
		if ((tmp1->fn == 0) && (tmp1 == (*start)))
		{
			free_way_down(tmp1->uk_way);
			free(*start);
			*start = tmp1->next;
		}
		else if ((tmp1->fn == 0) && (tmp1 != (*start)))
		{
			tmp2->next = tmp1->next;
			free_way_down(tmp1->uk_way);
			free(tmp1);
		}
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}

}

/*
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)(void*, void*))
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *begin_list;
	while (temp1)
	{
		if (!cmp(temp1->data, data_ref) && temp1 == *begin_list)
		{
			begin_list = temp1->next;
			free(temp1);
		}
		if (!cmp(temp1->date, data_ref) && temp1 != *begin_list)
		{
			temp2->next = temp1->next;
			free(temp1);
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
}*/