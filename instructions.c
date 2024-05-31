/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:08:35 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/20 11:28:16 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a)
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
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	int		tmp;
	t_list	*t;

	if (!b || !b->next)
		return ;
	t = b;
	tmp = *(int *)t->content;
	*(int *)t->content = *(int *)t->next->content;
	t = t->next;
	*(int *)t->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	int		tmp;
	t_list	*t;

	if (!a->next || !b->next)
		return ;
	t = b;
	tmp = *(int *)t->content;
	*(int *)t->content = *(int *)t->next->content;
	t = t->next;
	*(int *)t->content = tmp;
	t = a;
	tmp = *(int *)t->content;
	*(int *)t->content = *(int *)t->next->content;
	t = t->next;
	*(int *)t->content = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
	write(1, "pb\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
	write(1, "pa\n", 3);
}
