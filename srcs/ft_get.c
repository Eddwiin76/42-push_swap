/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:09:54 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/29 12:11:15 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_get_median(int *tab, int size)
{
	float	median;

	if (size % 2 != 0)
		median = tab[size / 2];
	else
		median = ((float)tab[size / 2] + (float)tab[(size / 2) + 1]) / 2;
	free(tab);
	return (median);
}

int	ft_get_pos_tab(int *tab, int min, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] == min)
		{
			free(tab);
			return (i);
		}
	}
	free(tab);
	return (-1);
}

int	ft_get_min_tab(int *tab, int size)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = -1;
	while (++i < size)
	{
		if (tab[i] < min)
			min = tab[i];
	}
	free(tab);
	return (min);
}

int	ft_get_max_tab(int *tab, int size)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = -1;
	while (++i < size)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	free(tab);
	return (max);
}

int	*ft_copy_to_tab(t_stacks *stacks, t_list *list, int max, int sort)
{
	int	i;
	int	*tab;

	tab = (int *)malloc(sizeof(int) * max + 1);
	if (!tab)
		ft_exit(stacks, "Malloc failed");
	i = 0;
	while (i < max)
	{
		tab[i] = *(int *)list->content;
		list = list->next;
		i++;
	}
	if (sort == 1)
		ft_sort_int_tab(tab, i);
	return (tab);
}
