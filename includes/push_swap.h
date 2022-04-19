/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:17:22 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/30 06:39:59 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stacks
{
	t_list		*a;
	t_list		*b;
}				t_stacks;

int		main(int ac, char **av);
void	ft_exit(t_stacks *stacks, char *msg);
int		ft_check_input(char **av, t_stacks *stacks);
int		ft_check_is_sorted(t_list *stack_a);
int		ft_verif_pos(t_stacks *stacks);
float	ft_get_median(int *tab, int size);
int		ft_get_pos_tab(int *tab, int min, int size);
int		ft_get_min_tab(int *tab, int size);
int		ft_get_max_tab(int *tab, int size);
int		*ft_copy_to_tab(t_stacks *stacks, t_list *list, int max, int sort);
void	ft_sort_three(t_stacks *stacks);
void	ft_sort_five(t_stacks *stacks);
void	ft_sort_stack(t_stacks *stacks, float median, int max, int b_size);
int		ft_sort_end(t_stacks *stacks, int max, int b_size);
int		ft_nb_1(t_list *stack);
int		ft_nb_2(t_list *stack);
int		ft_nb_3(t_list *stack);
void	ft_swap(t_stacks *stacks, char *msg);
void	ft_rotate(t_stacks *stacks, char *msg);
void	ft_push(t_stacks *stacks, char *msg);
void	ft_rev_rotate(t_stacks *stacks, char *msg);

#endif
// ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
