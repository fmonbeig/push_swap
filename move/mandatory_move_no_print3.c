/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move_no_print3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:28:24 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 16:52:15 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_no_print(t_data *d)
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
	}
}

void	rrb_no_print(t_data *d)
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
	}
}

void	rrr_no_print(t_data *d)
{
	rra_no_print(d);
	rrb_no_print(d);
	d->move++;
}
