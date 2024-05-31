/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:05:19 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/19 16:43:20 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(char **argv, t_list **a)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (argv[i])
	{
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j])
			make_addto_list(a, ft_atoi(arr[j++]));
		i++;
		free_arr(arr);
		free(arr);
	}
	if (!valid_params(a, argv) || !digits_args(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	valid_params(t_list **a, char **strs)
{
	int	*arr;
	int	i;

	arr = sort_intoarr(a);
	i = 0;
	while (arr[i + 1])
	{
		if (arr[i] == arr[i + 1])
			return (0);
		i++;
	}
	free(arr);
	i = 0;
	while (strs[i])
	{
		if (!ft_atol(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	soart(t_list **a, t_list **b)
{
	int	min;
	int	index;
	int	sze;

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
	while (sze > 4)
	{
		pb(b, a);
		sze--;
	}
	return (0);
}

int	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	acc;

	i = 0;
	sign = 1;
	acc = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		acc = acc * 10 + (str[i++] - '0');
		if (acc > 2147483647)
			return (0);
	}
	return (1);
}

int	digits_args(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]) && args[i][j] != ' '
				&& args[i][0] != '-' && args[i][0] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
