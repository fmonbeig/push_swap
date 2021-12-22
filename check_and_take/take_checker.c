/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:01:22 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 14:40:51 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*take_argument_checker(int argc, char **argv, t_data *d)
{
	int		i;
	int		j;
	t_list	*new;
	t_list	*ret;

	ret = NULL;
	i = 0;
	while (++i < argc)
	{
		d->ptr = ft_split(argv[i], ' ');
		j = -1;
		while (d->ptr[++j])
		{
			check_integer(d->ptr[j], d, ret);
			new = ft_lstnew(ft_atoi_push_swap(d->ptr[j], d));
			if (!new)
				free_all_failure_checker(d);
			ft_lstadd_back(&ret, new);
			d->argc++;
		}
		free_split(d->ptr, d);
	}
	check_duplicate(ret, d);
	return (ret);
}
