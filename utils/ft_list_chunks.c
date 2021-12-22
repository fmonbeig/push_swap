/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:45:15 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/08 15:21:28 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_chunks	*ft_lstnew_chunk(int *chunk, int len)
{
	t_chunks	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->nb = chunk;
	list->len = len;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back_chunk(t_chunks **alst, t_chunks *new)
{
	t_chunks	*last;

	if (!*alst)
		*alst = new;
	else
	{
		last = ft_lstlast_chunk(*alst);
		last->next = new;
	}
}

t_chunks	*ft_lstlast_chunk(t_chunks *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize_chunk(t_chunks *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstclear_chunk(t_chunks *lst)
{
	t_chunks	*lst_next;
	t_chunks	*delete;

	if (lst)
	{
		lst_next = lst->next;
		while (lst_next)
		{
			delete = lst_next;
			lst_next = lst_next->next;
			free (delete->nb);
			free (delete);
		}
		free (lst->nb);
		free(lst);
	}
}
