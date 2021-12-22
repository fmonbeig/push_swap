/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:44:12 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 17:31:59 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_action(t_data *d, char *line)
{
	ft_putstr_fd("Error\n", 2);
	get_next_line(0, &line, 1);
	free(line);
	free_all_failure_checker(d);
}

void	error_malloc_checker(t_data *d)
{
	ft_putstr_fd("Error\n", 2);
	free_all_failure_checker(d);
}

void	error_empty_arg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
