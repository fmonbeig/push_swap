/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo_insertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:26:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 15:31:07 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_chunk_on_pileb(t_data *d, int argc)
{
	int			i;
	t_chunks	*chunks;

	chunks = d->chunks;
	d->arg_pilea = argc;
	while (chunks)
	{
		i = -1;
		while (++i < chunks->len)
		{
			move_closest_nb_in_chunk_on_top(d, chunks);
			pb(d);
			d->arg_pilea--;
		}
		chunks = chunks->next;
	}
}

void	move_closest_nb_in_chunk_on_top(t_data *d, t_chunks *chunk)
{
	int	i;
	int	j;

	i = search_from_top(d, chunk);
	j = search_from_bottom(d, chunk);
	if (i <= j)
	{
		while (i--)
			ra(d);
	}
	else
	{
		while (j--)
			rra(d);
	}
}

void	push_on_pilea(t_data *d, int i, int argc)
{
	int	x;

	x = argc - i;
	if (i <= x)
	{
		while (i)
		{
			rb(d);
			i--;
		}
		pa(d);
	}
	else
	{
		while (x)
		{
			rrb(d);
			x--;
		}
		pa(d);
	}
}

void	sort_pileb_on_pilea(t_data *d, int argc)
{
	t_list	*temp;
	int		i;
	int		j;
	int		k;
	int		max;

	k = argc;
	j = -1;
	while (++j < k)
	{
		max = d->tab[argc - 1];
		temp = d->pileb;
		i = 0;
		while (temp)
		{
			if (temp->nb == max)
			{
				push_on_pilea(d, i, argc);
				argc--;
				break ;
			}
			temp = temp->next;
			i++;
		}
	}
}
