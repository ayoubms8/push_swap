/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:29:28 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/24 13:18:18 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;

	if (!(*a)->next)
		return ;
	tmp = (*a)->next;
	ft_lstadd_back(a, *a);
	*a = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*tmp;

	if (!(*b)->next)
		return ;
	tmp = (*b)->next;
	ft_lstadd_back(b, *b);
	*b = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*a)->next || !(*b)->next)
		return ;
	tmp = (*a)->next;
	ft_lstadd_back(a, *a);
	*a = tmp;
	tmp = (*b)->next;
	ft_lstadd_back(b, *b);
	*b = tmp;
	write(1, "rr\n", 3);
}

void	rra(t_list **a)
{
	if (!(*a)->next)
		return ;
	ft_lstadd_front_2(a, ft_ma9bllast(*a), ft_lstlast(*a));
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (!(*b)->next)
		return ;
	ft_lstadd_front_2(b, ft_ma9bllast(*b), ft_lstlast(*b));
	write(1, "rrb\n", 4);
}
