/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:19:36 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/20 15:15:03 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*str;
	int		n;
	char	**arr;

	if (argc <= 1)
		return (0);
	if (!parse(argv, &a))
		return (0);
	n = 1;
	str = ft_strdup("");
	while (n)
		str = ft_strjoin(str, get_next_line(0), &n);
	arr = ft_split(str, '\n');
	n = 0;
	argc = do_instructs(arr, &a, &b, &n);
	if (argc && (!is_sorted(a) || b))
		write(1, "KO\n", 3);
	else if (argc)
		write(1, "OK\n", 3);
	return (0);
}

int	do_instructs(char **arr, t_list **a, t_list **b, int *n)
{
	while (arr[*n])
	{
		if (do_instructs_2(arr, a, b, n))
			*n = *n;
		else if (ft_strncmp(arr[*n], "rb", 4) == 0)
			ra_c(b);
		else if (ft_strncmp(arr[*n], "rra", 4) == 0)
			rra_c(a);
		else if (ft_strncmp(arr[*n], "rrb", 4) == 0)
			rra_c(b);
		else if (ft_strncmp(arr[*n], "rr", 4) == 0)
			rr_c(a, b);
		else if (ft_strncmp(arr[*n], "ss", 4) == 0)
			ss_c(*a, *b);
		else if (ft_strncmp(arr[*n], "rrr", 4) == 0)
			rrr_c(a, b);
		else
			return (write(1, "Error\n", 6), 0);
		*n = *n + 1;
	}
	return (1);
}

int	do_instructs_2(char **arr, t_list **a, t_list **b, int *n)
{
	if (ft_strncmp(arr[*n], "sa", 4) == 0)
		return (sa_c(*a), 1);
	else if (ft_strncmp(arr[*n], "sb", 4) == 0)
		return (sa_c(*b), 1);
	else if (ft_strncmp(arr[*n], "pa", 4) == 0)
		return (pa_c(b, a), 1);
	else if (ft_strncmp(arr[*n], "pb", 4) == 0)
		return (pa_c(a, b), 1);
	else if (ft_strncmp(arr[*n], "ra", 4) == 0)
		return (ra_c(a), 1);
	return (0);
}
