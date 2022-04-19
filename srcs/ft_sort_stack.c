/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:58:44 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/28 19:10:56 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_a(t_stacks *stacks, float median, int max)
{
	int	count_ra;

	count_ra = 0;
	while (max-- > 0)
	{
		if (ft_nb_1(stacks->a) <= median)
		{
			ft_push(stacks, "pb");
		}
		else if (ft_nb_1(stacks->a) > median)
		{
			ft_rotate(stacks, "ra");
			count_ra++;
		}
	}
	return (count_ra);
}

void	ft_sort_b(t_stacks *stacks, float median, int max)
{
	while (max-- > 0 && ft_lstsize(stacks->b) > 2)
	{
		if (ft_nb_1(stacks->b) <= median)
			ft_rotate(stacks, "rb");
		else if (ft_nb_1(stacks->b) > median)
		{
			ft_push(stacks, "pa");
		}
	}
	if (ft_lstsize(stacks->b) == 2)
	{
		if (ft_nb_1(stacks->b) < ft_nb_2(stacks->b))
			ft_swap(stacks, "sb");
		ft_push(stacks, "pa");
		ft_push(stacks, "pa");
	}
}

int	ft_sort_end_next(t_stacks *stacks, int max, int b_size, int j)
{
	if (stacks->b)
		j += ft_sort_end(stacks, b_size, b_size);
	while (j < max)
	{
		if (ft_verif_pos(stacks) == 0)
			j += ft_sort_end(stacks, max - j, 0);
		else
			j++;
	}
	return (j);
}

int	ft_sort_end(t_stacks *stacks, int max, int b_size)
{
	static int	pass;
	int			j;
	int			count_ra;

	if (pass++ == 0)
		return (0);
	j = 0;
	count_ra = 0;
	if (b_size == 0 && max > 3)
	{
		count_ra = ft_sort_a(stacks, ft_get_median(ft_copy_to_tab(stacks,
						stacks->a, max, 1), max), max);
		while (count_ra-- > 0)
			ft_rev_rotate(stacks, "rra");
	}
	else if (stacks->b)
	{
		b_size = ft_lstsize(stacks->b);
		ft_sort_b(stacks, ft_get_median(ft_copy_to_tab(stacks, stacks->b,
					b_size, 1), b_size), b_size);
	}
	return (ft_sort_end_next(stacks, max, ft_lstsize(stacks->b), j));
}

void	ft_sort_stack(t_stacks *stacks, float median, int max, int b_size)
{
	static int	i;

	if (b_size == 0)
		ft_sort_a(stacks, median, max);
	else
		ft_sort_b(stacks, ft_get_median(ft_copy_to_tab(stacks, stacks->b,
					b_size, 1), b_size), b_size);
	if (stacks->b)
	{
		b_size = ft_lstsize(stacks->b);
		ft_sort_stack(stacks, ft_get_median(ft_copy_to_tab(stacks, stacks->b,
					b_size, 1), b_size), b_size, b_size);
	}
	i += ft_sort_end(stacks, max - i, 0);
}
