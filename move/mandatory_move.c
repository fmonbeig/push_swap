/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:47:56 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:22 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Push b - take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty
void	pb(t_data *d)
{
	t_list	*first;

	if (d->pilea)
	{
		first = d->pilea->next;
		ft_lstadd_front(&d->pileb, d->pilea);
		d->pilea = first;
	}
	d->move++;
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_data *d)
{
	t_list	*first;

	if (d->pileb)
	{
		first = d->pileb->next;
		ft_lstadd_front(&d->pilea, d->pileb);
		d->pileb = first;
	}
	d->move++;
	ft_putstr_fd("pa\n", 1);
}
// swap the first 2 elements at the top of stack a. Do nothing if there is only 
// one or no elements).

void	sa(t_data *d)
{
	int	temp;

	if (d->pilea && d->pilea->next)
	{
		temp = d->pilea->nb;
		d->pilea->nb = d->pilea->next->nb;
		d->pilea->next->nb = temp;
	}
	d->move++;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *d)
{
	int	temp;

	if (d->pileb && d->pileb->next)
	{
		temp = d->pileb->nb;
		d->pileb->nb = d->pileb->next->nb;
		d->pileb->next->nb = temp;
	}
	d->move++;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *d)
{
	sa_no_print(d);
	sb_no_print(d);
	d->move++;
	ft_putstr_fd("ss\n", 1);
}
