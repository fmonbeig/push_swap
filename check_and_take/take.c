/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:10:40 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/14 16:50:55 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_in_tab(t_data *d, int argc)
{
	int		i;
	t_list	*temp;

	temp = d->pilea;
	i = 0;
	d->tab = malloc(sizeof(int) * argc);
	if (!d->tab)
		error_malloc(d);
	while (temp)
	{
		d->tab[i] = temp->nb;
		temp = temp->next;
		i++;
	}
}

t_list	*take_argument(int argc, char **argv, t_data *d)
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
				free_all_failure(d);
			ft_lstadd_back(&ret, new);
			d->argc++;
		}
		free_split(d->ptr, d);
		d->ptr = NULL;
	}
	check_duplicate(ret, d);
	return (ret);
}

void	create_all_chunk(t_data *d)
{
	int	i;
	int	j;

	j = 0;
	d->len_chunk = d->argc / d->div;
	d->temp = malloc(sizeof(int *) * d->div);
	if (!d->temp)
		error_malloc(d);
	while (j < d->argc)
	{
		if (d->chunk_numb == d->div - 2)
			j = create_last_chunk(d, j);
		else
			j = create_chunk(d, j);
	}
	free(d->temp);
}

int	create_chunk(t_data *d, int j)
{
	int	i;

	i = -1;
	d->temp[++d->chunk_numb] = malloc(sizeof(int) * d->len_chunk);
	if (!d->temp[d->chunk_numb])
		error_malloc(d);
	while (++i < d->len_chunk)
		d->temp[d->chunk_numb][i] = d->tab[j++];
	ft_lstadd_back_chunk(&d->chunks, ft_lstnew_chunk(d->temp[d->chunk_numb],
			d->len_chunk));
	return (j);
}

int	create_last_chunk(t_data *d, int j)
{
	int	i;

	i = -1;
	d->temp[++d->chunk_numb] = malloc(sizeof(int) * d->len_chunk
			+ (d->argc % d->div));
	if (!d->temp[d->chunk_numb])
		error_malloc(d);
	while (++i < (d->len_chunk + (d->argc % d->div)))
		d->temp[d->chunk_numb][i] = d->tab[j++];
	ft_lstadd_back_chunk(&d->chunks, ft_lstnew_chunk(d->temp[d->chunk_numb],
			d->len_chunk + (d->argc % d->div)));
	return (j);
}
