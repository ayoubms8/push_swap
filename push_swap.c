/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:56:25 by alemsafi          #+#    #+#             */
/*   Updated: 2022/12/20 11:43:56 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		*arr;
	int		u;

	if (argc <= 1 || !parse(argv, &a))
		return (0);
	u = ft_lstsize(a) / 6;
	arr = sort_intoarr(&a);
	if (ft_lstsize(a) == 2 && *(int *)a->content > *(int *)a->next->content)
		ra(&a);
	if (ft_lstsize(a) == 3)
		so3rt(&a);
	if (ft_lstsize(a) > 3 && ft_lstsize(a) <= 10)
		so310rt(&a, &b);
	if (ft_lstsize(a) > 10 && ft_lstsize(a) <= 200)
		so100rt(&a, &b, arr, u);
	if (ft_lstsize(a) > 200 && ft_lstsize(a) <= 500)
	{
		u = ft_lstsize(a) / 11;
		so500rt(&a, &b, arr, u);
	}
	return (0);
}
