/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:01:57 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 15:20:51 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_mid(t_data *d, int argc)
{
	ft_sort_int_tab(d->tab, argc);
	return (d->tab[argc / 2]);
}

int	search_data_min_mid(t_data *d, int mid)
{
	t_list	*temp;

	temp = d->pilea;
	while (temp)
	{
		if (temp->nb < mid)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	search_data(t_data *d, int mid)
{
	t_list	*temp;

	temp = d->pilea;
	while (temp)
	{
		if (temp->nb != mid)
			return (1);
		temp = temp->next;
	}
	return (0);
}
