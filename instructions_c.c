/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:36:13 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/20 13:03:17 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_c(t_list *a)
{
	int		tmp;
	t_list	*t;

	if (!a || !a->next)
		return ;
	t = a;
	tmp = *(int *)t->content;
	*(int *)t->content = *(int *)t->next->content;
	t = t->next;
	*(int *)t->content = tmp;
}

void	pa_c(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
}

void	ra_c(t_list **a)
{
	t_list	*tmp;

	if (!(*a)->next)
		return ;
	tmp = (*a)->next;
	ft_lstadd_back(a, *a);
	*a = tmp;
}

void	rr_c(t_list **a, t_list **b)
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
}

void	rra_c(t_list **a)
{
	if (!(*a)->next)
		return ;
	ft_lstadd_front_2(a, ft_ma9bllast(*a), ft_lstlast(*a));
}
