/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_small_stack_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:50:32 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 20:24:15 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_two_elements_b(t_stack *stack_b)
{
	if (stack_b->top->value > stack_b->top->next->value)
		swap_b(stack_b);
}

void	sort_two_elements(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap_a(stack);
}

void	sort_three_elements(t_stack *stack)
{
	int		top;
	int		middle;
	int		bottom;

	top = stack->top->value;
	middle = stack->top->next->value;
	bottom = stack->bottom->value;
	if (top > middle && middle < bottom && top < bottom)
		swap_a(stack);
	else if (top > middle && middle > bottom)
	{
		swap_a(stack);
		rev_rotate_a(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_a(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rev_rotate_a(stack);
}

void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
