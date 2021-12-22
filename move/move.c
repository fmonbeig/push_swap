/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:21:42 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 16:44:49 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	split_pile_in_two(t_data *d, int argc, int mid)
{
	t_list	*temp;
	int		i;

	while (search_data_min_mid(d, mid))
	{
		temp = d->pilea;
		i = 0;
		while (temp)
		{
			if (temp->nb < mid)
			{
				push_on_pileb(d, i, argc);
				argc--;
				break ;
			}
			temp = temp->next;
			i++;
		}
	}
}

int	smallest_on_pileb(t_data *d)
{
	int		i;
	int		j;
	int		k;
	t_list	*temp;

	i = 0;
	k = 0;
	temp = d->pileb;
	if (temp)
		k = temp->nb;
	while (temp)
	{
		if (k > temp->nb)
			k = temp->nb;
		temp = temp->next;
	}
	return (k);
}
