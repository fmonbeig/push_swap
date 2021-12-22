/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:26:05 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 17:31:36 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_only_neg(char *str, t_data *d, t_list *ret)
{
	if (ft_strlen(str) == 1)
		if (str[0] == '-')
			error_not_integer(d, ret);
}

void	check_integer(char *str, t_data *d, t_list *ret)
{
	int	i;

	i = -1;
	check_only_neg(str, d, ret);
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			error_not_integer(d, ret);
	}
}

void	check_duplicate(t_list *ret, t_data *d)
{
	t_list	*temp;

	temp = NULL;
	while (ret->next)
	{
		temp = ret->next;
		while (temp)
		{
			if (ret->nb == temp->nb)
				error_duplicate(d, ret);
			temp = temp->next;
		}
		ret = ret->next;
	}
}

void	check_empty_arg(char **argv, int argc)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (ft_isalnum(argv[i][j]))
				flag = 1;
			j++;
		}
		if (!flag)
			error_empty_arg();
	}
}
