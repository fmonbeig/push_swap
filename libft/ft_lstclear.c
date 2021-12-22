/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:52:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 15:14:17 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*lst_next;
	t_list	*delete;

	if (lst)
	{
		lst_next = lst->next;
		while (lst_next)
		{
			delete = lst_next;
			lst_next = lst_next->next;
			free (delete);
		}
		free(lst);
	}
}
