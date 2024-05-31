/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:03 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/18 15:20:47 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_ma9bllast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

void	make_addto_list(t_list **a, int nbr)
{
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->content = malloc(sizeof(int));
	if (new_node->content == NULL)
		return ;
	*(int *)new_node->content = nbr;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new_node;
}

int	*sort_intoarr(t_list **a)
{
	int		*arr;
	int		i;
	t_list	*temp;

	temp = *a;
	i = 0;
	arr = ft_calloc(ft_lstsize(*a), sizeof(int));
	while (temp)
	{
		arr[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	arr = sort(arr, a);
	return (arr);
}

int	*sort(int *arr, t_list **a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < ft_lstsize(*a) - 1)
	{
		j = 0;
		while (j < ft_lstsize(*a) - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
}
