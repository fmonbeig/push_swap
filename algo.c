/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:44:47 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/20 10:40:23 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_simple(t_data *d, int argc)
{
	int		min;
	int		i;
	int		argc_pile_a ;
	t_list	*temp;

	put_in_tab(d, argc);
	ft_sort_int_tab(d->tab, argc);
	argc_pile_a = ascent_on_pileb(d, argc);
	algo_less_than_three(d, d->argc);
	d->j = argc + 1;
	while (--d->j - argc_pile_a)
		pa(d);
}

void	algo_less_than_three(t_data *d, int argc)
{
	int		i;
	t_list	*temp;

	if (argc <= 2 && check_sort_a(d))
		sa(d);
	else
	{
		if (d->pilea->nb > d->pilea->next->nb && check_sort_a(d))
			ra(d);
		if (d->pilea->nb < d->pilea->next->nb && check_sort_a(d))
			rra(d);
		if (check_sort_a(d))
			sa(d);
	}
}

void	algo_insertion(t_data *d, int argc)
{
	int		min;
	int		i;
	t_list	*temp;

	put_in_tab(d, argc);
	ft_sort_int_tab(d->tab, argc);
	create_all_chunk(d);
	move_chunk_on_pileb(d, argc);
	sort_pileb_on_pilea(d, argc);
}
