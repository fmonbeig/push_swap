/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:14:07 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 15:20:20 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_from_top(t_data *d, t_chunks *chunk)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = d->pilea;
	while (temp)
	{
		if (is_chunk(temp->nb, d->len_chunk, chunk))
		{
			d->hold_first = temp->nb;
			return (i);
		}
		i++;
		temp = temp->next;
	}
	return (0);
}

int	search_from_bottom(t_data *d, t_chunks *chunk)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = d->pilea;
	while (temp)
	{
		if (is_chunk(temp->nb, d->len_chunk, chunk))
		{
			d->hold_second = temp->nb;
			i = j;
		}
		j++;
		temp = temp->next;
	}
	return (d->arg_pilea - i);
}

int	is_chunk(int i, int len_chunk, t_chunks *chunk)
{
	int	j;

	j = -1;
	while (++j < len_chunk)
		if (i == chunk->nb[j])
			return (1);
	return (0);
}
