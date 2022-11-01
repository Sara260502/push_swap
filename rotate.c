/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarazicchieri <sarazicchieri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:05:24 by sarazicchie       #+#    #+#             */
/*   Updated: 2022/11/01 16:42:59 by sarazicchie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotate: first element becomes the last one*/

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_element;

	tmp = *stack;
	*stack = (*stack)->next;
	last_element = get_stack_bottom(*stack);
	tmp->next = NULL;
	last_element->next = tmp;
}

/*stdout_ra: first element of stack a becomes the last one
* prints "ra" to stdout*/
void	stdout_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*stdout_rb: first element of stack b becomes the last one
* prints "rb" to the stdout*/
void	stdout_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/*stdout_rr: ra and rb at the same time
* Prints "rr" to the standard output*/
void	stdout_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
