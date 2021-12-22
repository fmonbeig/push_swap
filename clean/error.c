/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:19:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 14:35:43 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_not_integer(t_data *d, t_list *ret)
{
	ft_putstr_fd("Error\n", 2);
	if (ret)
		ft_lstclear(ret);
	free_all_failure(d);
}

void	error_integer_big(t_data *d)
{
	ft_putstr_fd("Error\n", 2);
	free_all_failure(d);
}

void	error_integer_small(t_data *d)
{
	ft_putstr_fd("Error\n", 2);
	free_all_failure(d);
}

void	error_duplicate(t_data *d, t_list *ret)
{
	ft_putstr_fd("Error\n", 2);
	if (ret)
		ft_lstclear(ret);
	free_all_failure(d);
}

void	error_malloc(t_data *d)
{
	ft_putstr_fd("Error\n", 2);
	free_all_failure(d);
}
