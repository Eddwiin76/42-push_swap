/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:41:14 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/29 16:17:04 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_pos_next(t_stacks *stacks, int pos_min)
{
	if (pos_min == 1)
	{
		ft_swap(stacks, "sa");
		ft_rotate(stacks, "ra");
		return (1);
	}
	else if (pos_min == 2)
	{
		ft_push(stacks, "pb");
		ft_swap(stacks, "sa");
		ft_rotate(stacks, "ra");
		ft_push(stacks, "pa");
		return (1);
	}
	else if (pos_min == 3)
	{
		ft_push(stacks, "pb");
		ft_push(stacks, "pb");
		ft_swap(stacks, "sa");
		ft_rotate(stacks, "ra");
		ft_push(stacks, "pa");
		ft_push(stacks, "pa");
		return (1);
	}
	return (0);
}

int	ft_verif_pos(t_stacks *stacks)
{
	int	min;
	int	min_tab;
	int	pos_min;
	int	pos_min_tab;

	min_tab = ft_get_min_tab(ft_copy_to_tab(stacks, stacks->a,
				ft_lstsize(stacks->a), 0), ft_lstsize(stacks->a));
	pos_min_tab = ft_get_pos_tab(ft_copy_to_tab(stacks, stacks->a,
				ft_lstsize(stacks->a), 0), min_tab, ft_lstsize(stacks->a));
	min = ft_get_min_tab(ft_copy_to_tab(stacks, stacks->a,
				pos_min_tab, 0), pos_min_tab);
	if (pos_min_tab == 0)
		pos_min = pos_min_tab;
	else
		pos_min = ft_get_pos_tab(ft_copy_to_tab(stacks, stacks->a,
					ft_lstsize(stacks->a), 0), min, ft_lstsize(stacks->a));
	if (pos_min == 0)
	{
		ft_rotate(stacks, "ra");
		return (1);
	}
	else
		return (ft_verif_pos_next(stacks, pos_min));
}

int	ft_nb_1(t_list *stack)
{
	return (*(int *)stack->content);
}

int	ft_nb_2(t_list *stack)
{
	return (*(int *)stack->next->content);
}

int	ft_nb_3(t_list *stack)
{
	return (*(int *)stack->next->next->content);
}
