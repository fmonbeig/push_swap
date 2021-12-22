/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:59:25 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:29 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rotate a shift up all elements of stack a by 1. The first element becomes
// the last one
void	ra(t_data *d)
{
	t_list	*temp;

	if (d->pilea && d->pilea->next)
	{
		temp = d->pilea;
		d->pilea = d->pilea->next;
		ft_lstadd_back(&d->pilea, temp);
		temp->next = NULL;
		d->move++;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_data *d)
{
	t_list	*temp;

	if (d->pileb && d->pileb->next)
	{
		temp = d->pileb;
		d->pileb = d->pileb->next;
		ft_lstadd_back(&d->pileb, temp);
		temp->next = NULL;
		d->move++;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_data *d)
{
	ra_no_print(d);
	rb_no_print(d);
	d->move++;
	ft_putstr_fd("rr\n", 1);
}
