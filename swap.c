/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarazicchieri <sarazicchieri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:29:33 by sarazicchie       #+#    #+#             */
/*   Updated: 2022/11/01 16:58:13 by sarazicchie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap: swap the top 2 elements of a stack
*if stack is empty or there is only one 
*element it does nothing*/

static void	swap(t_stack *stack)
{
	int	a;

	if (stack == NULL || stack->next == NULL)
		return ;
	a = stack->value;
	stack->value = stack->next->value;
	stack->next->value = a;
	a = stack->index;
	stack->index = stack->next->index;
	stack->next->index = a;
}

/*stdout_sa: swap the top 2 elements of stack a. 
*prints "sa" to stdout*/

void	stdout_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/*stdout_sb: swap the top 2 elements of stack b.
*prints "sb" to stdout*/

void	stdout_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/*stdout_ss: sa and sb at the same time.
*prints "ss" to the stdout*/

void	stdout_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
