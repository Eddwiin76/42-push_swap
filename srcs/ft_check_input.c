/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:23:48 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/28 17:13:53 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_duplicate(int num, t_list *stack_a)
{
	(void)num;
	while (stack_a)
	{
		if (num == *(int *)stack_a->content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_check_input(char **av, t_stacks *stacks)
{
	int		i;
	long	*nbr;
	t_list	*new;

	i = 0;
	while (av[++i])
	{
		if (!ft_isnumeric(av[i]))
			return (1);
		nbr = malloc(sizeof(long));
		if (!nbr)
			ft_exit(stacks, "Malloc failed");
		*nbr = ft_atoi_long(av[i]);
		if ((*nbr < INT_MIN || *nbr > INT_MAX)
			|| ft_is_duplicate(*nbr, stacks->a))
		{
			free(nbr);
			return (1);
		}
		new = ft_lstnew(nbr);
		ft_lstadd_back(&stacks->a, new);
	}
	return (0);
}
