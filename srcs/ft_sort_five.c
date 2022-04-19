/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:28:52 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/29 22:16:56 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stacks *stacks)
{
	int	size_a;
	int	pos1;
	int	pos2;
	int	i;

	size_a = ft_lstsize(stacks->a);
	if (ft_nb_1(stacks->a) < ft_nb_2(stacks->a))
		ft_swap(stacks, "sa");
	pos1 = ft_get_pos_tab(ft_copy_to_tab(stacks, stacks->a, size_a, 1),
			ft_nb_2(stacks->a), size_a);
	pos2 = ft_get_pos_tab(ft_copy_to_tab(stacks, stacks->a, size_a, 1),
			ft_nb_1(stacks->a), size_a);
	ft_push(stacks, "pb");
	ft_push(stacks, "pb");
	ft_sort_three(stacks);
	i = -1;
	while (++i <= size_a - 1)
	{
		if (i == pos1 || i == pos2)
			ft_push(stacks, "pa");
		ft_rotate(stacks, "ra");
	}
}
