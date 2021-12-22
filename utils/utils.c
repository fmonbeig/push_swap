/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:08:46 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 14:09:49 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_push_swap(const char *str, t_data *d)
{
	unsigned long long int	num;
	int						neg;

	num = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	if (num > 2147483648 && neg == -1)
		error_integer_small(d);
	if (num > 2147483647 && neg == 1)
		error_integer_big(d);
	return (num * neg);
}

// Permet de detacher la derniere liste en mettant NULL a la liste d'avant
t_list	*ft_lstlast_detach(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	while (lst->next)
	{
		temp = lst;
		lst = lst->next;
	}
	temp->next = NULL;
	return (lst);
}
