/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:51:25 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 15:42:05 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_pile(t_data *d)
{
	t_list	*pilea;
	t_list	*pileb;

	pilea = d->pilea;
	pileb = d->pileb;
	ft_putstr_fd("\n\n", 1);
	while (pilea || pileb)
	{
		if (pilea)
			ft_putnbr(pilea->nb);
		else
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(" ", 1);
		if (pileb)
			ft_putnbr(pileb->nb);
		else
			ft_putstr_fd(" ", 1);
		if (pilea)
			pilea = pilea->next;
		if (pileb)
			pileb = pileb->next;
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("_ _\nA B\nMove : ", 1);
	ft_putnbr(d->move);
}

void	print_chunk(t_data *d, int argc)
{
	t_chunks	*temp;
	int			i;
	int			j;

	j = 1;
	temp = d->chunks;
	while (temp)
	{
		i = -1;
		while (++i < temp->len)
		{
			ft_putstr_fd("chunk ", 1);
			ft_putnbr(j);
			ft_putstr_fd(" --> ", 1);
			ft_putnbr(temp->nb[i]);
		}
		temp = temp->next;
		j++;
	}
}
