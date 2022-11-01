/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarazicchieri <sarazicchieri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:24:39 by sarazicchie       #+#    #+#             */
/*   Updated: 2022/11/01 16:44:35 by sarazicchie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push_all_save_three: 
*Pushes all the elements of stack a into stack b, except the three last ones.
* Pushes the smaller values first, and then the larger values 
*to help with sorting efficiency */

static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	stack_size = get_stack_size(*stack_a);
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			stdout_pb(stack_a, stack_b);
			pushed++;
		}
		else
			stdout_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		stdout_pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack: 
*After the bulk of the stack is sorted, 
*shifts stack a until the lowest value is at the top. 
*If it is in the bottom half of the stack, reverse rotate it into position, 
*otherwise rotate until it is at the top of the stack */
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			stdout_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			stdout_ra(stack_a);
			lowest_pos--;
		}
	}
}

/*sort: Sorting algorithm for a stack larger than 3. 
*Push everything but 3 numbers to stack B.
* Sort the 3 numbers left in stack A.
* Calculate the most cost-effective move. 
*Shift elements until stack A is in order */
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	small_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}