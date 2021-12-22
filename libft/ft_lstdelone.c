/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 23:07:47 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/08/10 14:25:27 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->nb);
		free(lst);
		lst = NULL;
	}
}
