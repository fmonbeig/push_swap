/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:35:33 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 15:29:12 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_all_failure(t_data *d)
{
	if (d->ptr)
		free_split(d->ptr, d);
	if (d->tab)
		free(d->tab);
	if (d->pilea)
		ft_lstclear(d->pilea);
	if (d->pileb)
		ft_lstclear(d->pileb);
	if (d->chunks)
		ft_lstclear_chunk(d->chunks);
	if (d)
		free (d);
	exit(EXIT_FAILURE);
}

void	free_all_success(t_data *d)
{
	if (d->ptr)
		free_split(d->ptr, d);
	if (d->tab)
		free(d->tab);
	if (d->pilea)
		ft_lstclear(d->pilea);
	if (d->pileb)
		ft_lstclear(d->pileb);
	if (d->chunks)
		ft_lstclear_chunk(d->chunks);
	if (d)
		free (d);
	exit(EXIT_SUCCESS);
}

void	free_all_failure_checker(t_data *d)
{
	if (d->ptr)
		free_split(d->ptr, d);
	if (d->pilea)
		ft_lstclear(d->pilea);
	if (d->pileb)
		ft_lstclear(d->pileb);
	if (d)
		free (d);
	exit(EXIT_FAILURE);
}

void	free_all_success_checker(t_data *d)
{
	if (d->ptr)
		free_split(d->ptr, d);
	if (d->pilea)
		ft_lstclear(d->pilea);
	if (d->pileb)
		ft_lstclear(d->pileb);
	if (d)
		free (d);
	exit(EXIT_SUCCESS);
}

void	free_split(char **ptr, t_data *d)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		free_all_failure(d);
	while (ptr[i])
		free (ptr[i++]);
	free(ptr);
}
