/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarazicchieri <sarazicchieri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:19:01 by sarazicchie       #+#    #+#             */
/*   Updated: 2022/11/01 16:45:34 by sarazicchie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */

t_stack		*fill_stack_values(char **av);
void		assign_index(t_stack *stack_a, int ac);

/* Sorting Algorithms */

int			is_sorted(t_stack *stack);
void		small_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position */

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		stdout_pa(t_stack **stack_a, t_stack **stack_b);
void		stdout_pb(t_stack **stack_a, t_stack **stack_b);
void		stdout_sa(t_stack **stack_a);
void		stdout_sb(t_stack **stack_b);
void		stdout_ss(t_stack **stack_a, t_stack **stack_b);
void		stdout_ra(t_stack **stack_a);
void		stdout_rb(t_stack **stack_b);
void		stdout_rr(t_stack **stack_a, t_stack **stack_b);
void		stdout_rrr(t_stack **stack_a, t_stack **stack_b);
void		stdout_rra(t_stack **stack_a);
void		stdout_rrb(t_stack **stack_b);

/* Stack Functions */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* Utils */

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

/* Error */

void		exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

char		**ft_split(char const *s, char c);
char		**is_correct_input(char **av, int ac);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
int			calc_matrix_len(char **matrix);

#endif
