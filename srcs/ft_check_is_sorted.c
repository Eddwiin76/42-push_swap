/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:52:32 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/28 17:15:21 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (ft_nb_1(stack_a) > ft_nb_2(stack_a))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
