/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:27:05 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/24 13:17:36 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int		digits_args(char **args);
void	free_arr(char **arr);
int		parse(char **argv, t_list **a);
void	make_addto_list(t_list **a, int nbr);
t_list	*ft_ma9bllast(t_list *lst);
int		*sort_intoarr(t_list **a);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list**b);
void	so3rt(t_list **a);
int		so310rt(t_list **a, t_list **b);
int		soort(t_list **b, t_list **a);
int		soart(t_list **a, t_list **b);
int		so100rt(t_list **a, t_list **b, int *arr, int u);
int		so500rt(t_list **a, t_list **b, int *arr, int u);
int		*sort(int *arr, t_list **a);
int		get_indexinf(t_list **a, int unit, int *n);
int		get_index_ofmin(t_list **a, int *min);
int		get_index(t_list **a, int jibindexdiali);
int		get_index_ofmax(t_list **a, int *max);
int		valid_params(t_list **a, char **strs);
int		ft_atol(char *str);
int		do_instructs(char **arr, t_list **a, t_list **b, int *n);
int		do_instructs_2(char **arr, t_list **a, t_list **b, int *n);
int		is_sorted(t_list *a);
void	sa_c(t_list *a);
void	pa_c(t_list **a, t_list **b);
void	ra_c(t_list **a);
void	rr_c(t_list **a, t_list **b);
void	rra_c(t_list **a);
void	ss_c(t_list *a, t_list *b);
void	rrr_c(t_list **a, t_list **b);

#endif