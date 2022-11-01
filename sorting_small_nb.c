/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarazicchieri <sarazicchieri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:27:47 by sarazicchie       #+#    #+#             */
/*   Updated: 2022/11/01 16:42:59 by sarazicchie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_highest_index: Returns the highest index in a stack */
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* small_sort: 
*Sorts a stack of 3 numbers in 2 or fewer moves.
* The sorting is done by index rather than value.
* values:	 0	 9	 2
* indexes:	[1]	[3]	[2]
* rra:
* values:	 2	 0	 9
* indexes:	[2]	[1]	[3]
* sa:
* values:	 0	 2	 9
* indexes:	[1]	[2]	[3]*/
void	small_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		stdout_ra(stack);
	else if ((*stack)->next->index == highest)
		stdout_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		stdout_sa(stack);
}
