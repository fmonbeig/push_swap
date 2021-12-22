/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:28:24 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:37 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_data *d)
{
	t_list	*temp;
	t_list	*first;

	if (d->pilea && d->pilea->next)
	{
		first = ft_lstlast_detach(d->pilea);
		temp = d->pilea;
		d->pilea = first;
		d->pilea->next = temp;
		d->move++;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_data *d)
{
	t_list	*temp;
	t_list	*first;

	if (d->pileb && d->pileb->next)
	{
		first = ft_lstlast_detach(d->pileb);
		temp = d->pileb;
		d->pileb = first;
		d->pileb->next = temp;
		d->move++;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_data *d)
{
	rra_no_print(d);
	rrb_no_print(d);
	d->move++;
	ft_putstr_fd("rrr\n", 1);
}
