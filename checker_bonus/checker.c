/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:22:11 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/12/22 11:48:21 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	return (d);
}

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc > 1)
	{
		d = init();
		check_empty_arg(argv, argc);
		d->pilea = take_argument(argc, argv, d);
		read_action(d);
		if (!check_sort(d))
			ft_putstr("OK");
		else
			ft_putstr("KO");
		free_all_success_checker(d);
	}
	return (1);
}

void	read_action(t_data *d)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(0, &line, 0);
		if (ret > 0)
			do_action(line, d);
		free(line);
	}
}

void	do_action(char *line, t_data *d)
{
	if (ft_strncmp(line, "ra", 5) == 0)
		ra_no_print(d);
	else if (ft_strncmp(line, "rb", 5) == 0)
		rb_no_print(d);
	else if (ft_strncmp(line, "rr", 5) == 0)
		rr_no_print(d);
	else if (ft_strncmp(line, "pa", 5) == 0)
		pa_no_print(d);
	else if (ft_strncmp(line, "pb", 5) == 0)
		pb_no_print(d);
	else if (ft_strncmp(line, "rra", 5) == 0)
		rra_no_print(d);
	else if (ft_strncmp(line, "rrb", 5) == 0)
		rrb_no_print(d);
	else if (ft_strncmp(line, "rrr", 5) == 0)
		rrr_no_print(d);
	else if (ft_strncmp(line, "sa", 5) == 0)
		sa_no_print(d);
	else if (ft_strncmp(line, "sb", 5) == 0)
		sb_no_print(d);
	else if (ft_strncmp(line, "ss", 5) == 0)
		ss_no_print(d);
	else
		error_action(d, line);
}
