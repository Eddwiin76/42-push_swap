/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:44 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/28 16:03:34 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char *msg)
{
	void	*tmp;

	if (ft_strcmp(msg, "sa") == 0 || ft_strcmp(msg, "ss") == 0)
	{
		tmp = stacks->a->content;
		stacks->a->content = stacks->a->next->content;
		stacks->a->next->content = tmp;
	}
	if (ft_strcmp(msg, "sb") == 0 || ft_strcmp(msg, "ss") == 0)
	{
		tmp = stacks->b->content;
		stacks->b->content = stacks->b->next->content;
		stacks->b->next->content = tmp;
	}
	ft_printf("%s\n", msg);
}

void	ft_push(t_stacks *stacks, char *msg)
{
	t_list	*tmp;

	if (ft_strcmp(msg, "pa") == 0)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		tmp->next = NULL;
		ft_lstadd_front(&stacks->a, tmp);
	}
	if (ft_strcmp(msg, "pb") == 0)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		tmp->next = NULL;
		ft_lstadd_front(&stacks->b, tmp);
	}
	ft_printf("%s\n", msg);
}

void	ft_rotate(t_stacks *stacks, char *msg)
{
	t_list	*tmp;

	if (ft_strcmp(msg, "ra") == 0 || ft_strcmp(msg, "rr") == 0)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		tmp->next = NULL;
		ft_lstadd_back(&stacks->a, tmp);
	}
	if (ft_strcmp(msg, "rb") == 0 || ft_strcmp(msg, "rr") == 0)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		tmp->next = NULL;
		ft_lstadd_back(&stacks->b, tmp);
	}
	ft_printf("%s\n", msg);
}

void	ft_rev_rotate(t_stacks *stacks, char *msg)
{
	t_list	*tmp_last;
	t_list	*tmp;

	if (ft_strcmp(msg, "rra") == 0 || ft_strcmp(msg, "rrr") == 0)
	{
		tmp = stacks->a;
		tmp_last = ft_lstlast(stacks->a);
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(&stacks->a, tmp_last);
		tmp->next = NULL;
	}
	if (ft_strcmp(msg, "rrb") == 0 || ft_strcmp(msg, "rrr") == 0)
	{
		tmp = stacks->b;
		tmp_last = ft_lstlast(stacks->b);
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(&stacks->b, tmp_last);
		tmp->next = NULL;
	}
	ft_printf("%s\n", msg);
}
