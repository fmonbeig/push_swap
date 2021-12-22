/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:02:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/20 13:38:01 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		exit(EXIT_FAILURE);
	d->pilea = NULL;
	d->pileb = NULL;
	d->chunks = NULL;
	d->chunk_numb = -1;
	d->div = 0;
	d->move = 0;
	d->argc = 0;
	d->rb = 0;
	d->rrb = 0;
	d->ra = 0;
	d->rra = 0;
	d->tab = 0;
	d->temp = 0;
	d->len_chunk = 0;
	d->j = 0;
	d->hold_first = 0;
	d->hold_second = 0;
	d->ptr = NULL;
	return (d);
}

void	change_div(t_data *d)
{
	if (d->argc <= 100)
		d->div = 5;
	else if (d->argc > 100 && d->argc <= 200)
		d->div = 6;
	else if (d->argc > 200 && d->argc <= 300)
		d->div = 8;
	else if (d->argc > 300 && d->argc <= 400)
		d->div = 9;
	else if (d->argc > 400 && d->argc <= 550)
		d->div = 11;
	else if (d->argc > 550)
		d->div = d->argc / 50;
}

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc > 1)
	{
		d = init();
		check_empty_arg(argv, argc);
		d->pilea = take_argument(argc, argv, d);
		change_div(d);
		if (check_sort(d))
		{
			if (d->argc <= 3)
				algo_less_than_three(d, d->argc);
			else if (d->argc <= 10)
				algo_simple(d, d->argc);
			else
				algo_insertion(d, d->argc);
		}
		free_all_success(d);
	}
	return (1);
}
