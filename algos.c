/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:42:51 by alemsafi          #+#    #+#             */
/*   Updated: 2023/03/24 23:17:26 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	so3rt(t_list **a)
{
	if (*(int *)(*a)->content < *(int *)(*a)->next->content &&
		*(int *)(*a)->next->content < *(int *)(*a)->next->next->content)
		return ;
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
	{
		if (*(int *)(*a)->next->content > *(int *)(*a)->next->next->content)
		{
			sa(*a);
			rra(a);
		}
		else if (*(int *)(*a)->content > *(int *)(*a)->next->next->content)
			ra(a);
		else
			sa(*a);
	}
	else if (*(int *)(*a)->content > *(int *)(*a)->next->next->content)
		rra(a);
	else
	{
		sa(*a);
		ra(a);
	}
}

int	so310rt(t_list **a, t_list **b)
{
	int	min;
	int	index;
	int	sze;

	if (is_sorted(*a))
		return (0);
	sze = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3)
	{
		index = get_index_ofmin(a, &min);
		while (*(int *)(*a)->content != min && ft_lstsize(*a) / 2 > index)
			ra(a);
		while (*(int *)(*a)->content != min && ft_lstsize(*a) / 2 <= index)
			rra(a);
		pa(a, b);
	}
	so3rt(a);
	while (sze > 3)
	{
		pb(b, a);
		sze--;
	}
	return (0);
}

int	soort(t_list **b, t_list **a)
{
	int	max;
	int	index;

	while (ft_lstsize(*b) > 0)
	{
		index = get_index_ofmax(b, &max);
		while (*(int *)(*b)->content != max)
		{
			if (ft_lstsize(*b) / 2 > index)
				rb(b);
			else
				rrb(b);
		}
		pb(b, a);
	}
	return (1);
}

int	so100rt(t_list **a, t_list **b, int *arr, int u)
{
	int	q;
	int	n;

	q = 1;
	while (q < 6)
	{
		while (ft_lstsize(*b) < u * q)
		{
			while (*(int *)(*a)->content > arr[u * q] && ft_lstsize(*a)
				/ 2 > get_indexinf(a, arr[u * q], &n))
			{
				if (*b && (*b)->next && get_indexinf(b, arr[u * q - u / 2], &n)
					&& *(int *)(*b)->content > n)
					rr(a, b);
				else
					ra(a);
			}
			while (*(int *)(*a)->content > arr[u * q] && ft_lstsize(*a)
				/ 2 <= get_indexinf(a, arr[u * q], &n))
				rra(a);
			pa(a, b);
		}
		q++;
	}
	return (soart(a, b), soort(b, a));
}

int	so500rt(t_list **a, t_list **b, int *arr, int u)
{
	int	q;
	int	n;

	q = 1;
	while (q < 11)
	{
		while (ft_lstsize(*b) < u * q)
		{
			while (*(int *)(*a)->content > arr[u * q] && ft_lstsize(*a)
				/ 2 > get_indexinf(a, arr[u * q], &n))
			{
				if (*b && (*b)->next && get_indexinf(b, arr[u * q - u / 2], &n)
					&& *(int *)(*b)->content > n)
					rr(a, b);
				else
					ra(a);
			}
			while (*(int *)(*a)->content > arr[u * q] && ft_lstsize(*a)
				/ 2 < get_indexinf(a, arr[u * q], &n))
				rra(a);
			pa(a, b);
		}
		q++;
	}
	return (soart(a, b), soort(b, a));
}
