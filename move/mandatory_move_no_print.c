/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_move_no_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:47:56 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:46 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_no_print(t_data *d)
{
	t_list	*first;

	if (d->pilea)
	{
		first = d->pilea->next;
		ft_lstadd_front(&d->pileb, d->pilea);
		d->pilea = first;
	}
	d->move++;
}

void	pa_no_print(t_data *d)
{
	t_list	*first;

	if (d->pileb)
	{
		first = d->pileb->next;
		ft_lstadd_front(&d->pilea, d->pileb);
		d->pileb = first;
	}
	d->move++;
}

void	sa_no_print(t_data *d)
{
	int	temp;

	if (d->pilea && d->pilea->next)
	{
		temp = d->pilea->nb;
		d->pilea->nb = d->pilea->next->nb;
		d->pilea->next->nb = temp;
	}
	d->move++;
}

void	sb_no_print(t_data *d)
{
	int	temp;

	if (d->pileb && d->pileb->next)
	{
		temp = d->pileb->nb;
		d->pileb->nb = d->pileb->next->nb;
		d->pileb->next->nb = temp;
	}
	d->move++;
}

void	ss_no_print(t_data *d)
{
	sa_no_print(d);
	sb_no_print(d);
	d->move++;
}
