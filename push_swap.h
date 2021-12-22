/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:02:48 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/09/20 10:39:39 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include "libft/libft.h"
# define BUFFER_SIZE 10

typedef struct s_chunks
{
	int				*nb;
	int				len;
	struct s_chunks	*next;
}		t_chunks;

typedef struct s_data
{
	t_list		*pilea;
	t_list		*pileb;
	t_chunks	*chunks;
	int			move;
	int			*tab;
	int			**temp;
	int			argc;
	int			arg_pilea;
	int			len_chunk;
	int			chunk_numb;
	int			j;
	int			div;
	int			hold_first;
	int			hold_second;
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	char		**ptr;
}		t_data;

//utils
int			ft_atoi_push_swap(const char *str, t_data *d);
t_list		*ft_lstlast_detach(t_list *lst);
//ft_list_chunk
t_chunks	*ft_lstnew_chunk(int *chunk, int len);
void		ft_lstadd_back_chunk(t_chunks **alst, t_chunks *new);
t_chunks	*ft_lstlast_chunk(t_chunks *lst);
int			ft_lstsize_chunk(t_chunks *lst);
void		ft_lstclear_chunk(t_chunks *lst);
// main
int			main(int argc, char **argv);
void		change_div(t_data *d);
t_data		*init(void);
//error
void		error_not_integer(t_data *d, t_list *ret);
void		error_integer_big(t_data *d);
void		error_integer_small(t_data *d);
void		error_duplicate(t_data *d, t_list *ret);
void		error_malloc(t_data *d);
void		error_malloc_checker(t_data *d);
void		error_action(t_data *d, char *line);
void		error_empty_arg(void);
//check
void		check_only_neg(char *str, t_data *d, t_list *ret);
void		check_integer(char *str, t_data *d, t_list *ret);
void		check_duplicate(t_list *ret, t_data *d);
int			check_smallest_or_biggest(t_data *d, int closest);
int			check_biggest(t_data *d, int closest);
int			check_smallest(t_data *d, int closest);
void		check_empty_arg(char **argv, int argc);
//take
t_list		*take_argument(int argc, char **argv, t_data *d);
void		put_in_tab(t_data *d, int argc);
void		create_all_chunk(t_data *d);
int			create_last_chunk(t_data *d, int j);
int			create_chunk(t_data *d, int j);
t_list		*take_argument_checker(int argc, char **argv, t_data *d);
//free
void		free_all_failure(t_data *d);
void		free_all_success(t_data *d);
void		free_split(char **ptr, t_data *d);
void		free_all_failure_checker(t_data *d);
void		free_all_success_checker(t_data *d);
//mandatory move
void		pb(t_data *d);
void		pa(t_data *d);
void		sa(t_data *d);
void		sb(t_data *d);
void		ss(t_data *d);
void		ra(t_data *d);
void		rb(t_data *d);
void		rr(t_data *d);
void		rra(t_data *d);
void		rrb(t_data *d);
void		rrr(t_data *d);
//mandatory move_no_print
void		pb_no_print(t_data *d);
void		pa_no_print(t_data *d);
void		sa_no_print(t_data *d);
void		sb_no_print(t_data *d);
void		ss_no_print(t_data *d);
void		ra_no_print(t_data *d);
void		rb_no_print(t_data *d);
void		rra_no_print(t_data *d);
void		rrb_no_print(t_data *d);
void		rr_no_print(t_data *d);
void		rrr_no_print(t_data *d);
//move
void		push_on_pileb(t_data *d, int i, int argc);
void		move_chunk_on_pileb(t_data *d, int argc);
void		move_closest_nb_in_chunk_on_top(t_data *d, t_chunks *chunk);
void		move_smallest_nb_pileb_on_top(t_data *d, int small);
void		push_on_pilea(t_data *d, int i, int argc);
void		sort_pileb_on_pilea(t_data *d, int argc);
void		move_smallest_on_pileb(t_data *d);
//algo
void		algo_fusion(t_data *d, int argc);
int			ascent_on_pileb(t_data *d, int argc);
void		split_pile_in_two(t_data *d, int argc, int mid);
void		algo_simple(t_data *d, int argc);
void		algo_less_than_three(t_data *d, int argc);
void		algo_insertion(t_data *d, int argc);
//sort
void		sort_a_and_b(t_data *d);
int			check_sort(t_data *d);
int			check_sort_b(t_data *d);
int			check_sort_a(t_data *d);
//find
int			find_mid(t_data *d, int argc);
int			search_data(t_data *d, int mid);
int			search_data_min_mid(t_data *d, int mid);
int			search_from_top(t_data *d, t_chunks *chunk);
int			search_from_bottom(t_data *d, t_chunks *chunk);
int			is_chunk(int i, int len_chunk, t_chunks *chunk);
int			search_smallest_nb_from_top(t_data *d, int small);
int			search_smallest_nb_from_bottom(t_data *d, int small);
int			smallest_on_pileb(t_data *d);
//GNL
char		*ft_strjoin_get_next_line(const char *s1, const char *s2);
int			get_next_line(int fd, char **line, int flag);
//print
void		print_pile(t_data *d);
void		print_chunk(t_data *d, int argc);
//checker
void		read_action(t_data *d);
void		do_action(char *line, t_data *d);

#endif
