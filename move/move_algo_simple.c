/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:53:29 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 15:31:24 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ascent_on_pileb(t_data *d, int argc)
{
	t_list	*temp;
	int		i;
	int		n;
	int		min;

	n = -1;
	while (check_sort_a(d) && argc > 3)
	{
		min = d->tab[++n];
		temp = d->pilea;
		i = 0;
		while (temp)
		{
			if (temp->nb == min)
			{
				push_on_pileb(d, i, argc);
				argc--;
				break ;
			}
			temp = temp->next;
			i++;
		}
	}
	return (argc);
}

void	push_on_pileb(t_data *d, int i, int argc)
{
	int	x;

	x = argc - i;
	if (i <= x)
	{
		while (i)
		{
			ra(d);
			i--;
		}
		pb(d);
	}
	else
	{
		while (x)
		{
			rra(d);
			x--;
		}
		pb(d);
	}
}
