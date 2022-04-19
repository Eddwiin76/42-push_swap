/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:24:09 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/27 12:22:05 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_next(t_stacks *stacks)
{
	if (ft_nb_1(stacks->a) > ft_nb_2(stacks->a)
		&& ft_nb_2(stacks->a) < ft_nb_3(stacks->a)
		&& ft_nb_3(stacks->a) < ft_nb_1(stacks->a))
		ft_rotate(stacks, "ra");
	else if (ft_nb_1(stacks->a) > ft_nb_2(stacks->a)
		&& ft_nb_2(stacks->a) < ft_nb_3(stacks->a)
		&& ft_nb_3(stacks->a) > ft_nb_1(stacks->a))
		ft_swap(stacks, "sa");
}

void	ft_sort_three(t_stacks *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		ft_verif_pos(stacks);
	else
	{
		if ((ft_nb_1(stacks->a) < ft_nb_2(stacks->a))
			&& (ft_nb_2(stacks->a) > ft_nb_3(stacks->a))
			&& (ft_nb_3(stacks->a) > ft_nb_1(stacks->a)))
		{
			ft_rev_rotate(stacks, "rra");
			ft_swap(stacks, "sa");
		}
		else if (ft_nb_1(stacks->a) < ft_nb_2(stacks->a)
			&& ft_nb_2(stacks->a) > ft_nb_3(stacks->a)
			&& ft_nb_3(stacks->a) < ft_nb_1(stacks->a))
			ft_rev_rotate(stacks, "rra");
		else if (ft_nb_1(stacks->a) > ft_nb_2(stacks->a)
			&& ft_nb_2(stacks->a) > ft_nb_3(stacks->a))
		{
			ft_swap(stacks, "sa");
			ft_rev_rotate(stacks, "rra");
		}
		else
			ft_sort_three_next(stacks);
	}
}
