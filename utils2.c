/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:15:07 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/20 11:27:22 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **a, t_list**b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	ft_lstadd_front_2(a, ft_ma9bllast(*a), ft_lstlast(*a));
	ft_lstadd_front_2(b, ft_ma9bllast(*b), ft_lstlast(*b));
	write(1, "rrr\n", 4);
}

int	get_index_ofmin(t_list **a, int *min)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	*min = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content < *min)
			*min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (*(int *)tmp->content == *min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	get_index(t_list **a, int jibindexdiali)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (*(int *)tmp->content == jibindexdiali)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	get_indexinf(t_list **a, int unit, int *n)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		*n = *(int *)tmp->content;
		if (*(int *)tmp->content < unit)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	get_index_ofmax(t_list **a, int *max)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	*max = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content > *max)
			*max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (*(int *)tmp->content == *max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
