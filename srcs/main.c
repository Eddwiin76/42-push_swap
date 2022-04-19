/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:17:50 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/29 22:17:59 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stacks *stacks, char *msg)
{
	if (stacks->a)
		ft_lstclear(&stacks->a, free);
	if (stacks->b)
		ft_lstclear(&stacks->b, free);
	if (msg)
		ft_printf("%s\n", msg);
	exit (0);
}

void	ft_choise_sort(t_stacks *stacks)
{
	if (ft_lstsize(stacks->a) <= 3)
		ft_sort_three(stacks);
	else if (ft_lstsize(stacks->a) > 3 && ft_lstsize(stacks->a) <= 5)
		ft_sort_five(stacks);
	else
		ft_sort_stack(stacks, ft_get_median(ft_copy_to_tab(stacks,
					stacks->a, ft_lstsize(stacks->a), 1),
				ft_lstsize(stacks->a)), ft_lstsize(stacks->a), 0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (ac > 1)
	{
		if (ft_check_input(av, &stacks) == 1)
			ft_exit(&stacks, "Error");
		if (ft_check_is_sorted(stacks.a) == 1)
			ft_choise_sort(&stacks);
	}
	ft_exit(&stacks, NULL);
	return (0);
}
