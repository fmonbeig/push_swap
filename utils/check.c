/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:47:23 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 11:39:49 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_data *d)
{
	t_list	*pilea;
	t_list	*pileb;

	pilea = d->pilea;
	pileb = d->pileb;
	if (pileb)
		return (1);
	while (pilea && pilea->next)
	{
		if (pilea->nb > pilea->next->nb)
			return (1);
		pilea = pilea->next;
	}
	return (0);
}

int	check_sort_b(t_data *d)
{
	t_list	*pileb;

	pileb = d->pileb;
	while (pileb->next)
	{
		if (pileb->nb < pileb->next->nb)
			return (1);
		pileb = pileb->next;
	}
	return (0);
}

int	check_sort_a(t_data *d)
{
	t_list	*pilea;

	pilea = d->pilea;
	while (pilea && pilea->next)
	{
		if (pilea->nb > pilea->next->nb)
			return (1);
		pilea = pilea->next;
	}
	return (0);
}
