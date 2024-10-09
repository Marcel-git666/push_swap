/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:29:02 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 18:59:47 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	handle_rotations(t_stack *stack_a, t_stack *stack_b, int *rotations)
{
	if (cmp(stack_b->top, stack_a->top) < 0)
	{
		push_a(stack_a, stack_b);
		if (*rotations > 0 && cmp(stack_a->top, stack_a->bottom) > 0)
			reverse_rotations(stack_a, rotations);
	}
	else if (cmp(stack_b->top, stack_a->top) > 0
		&& cmp(stack_a->bottom, stack_b->top) <= 0)
	{
		rotate_a(stack_a);
		(*rotations)++;
	}
	else
	{
		push_a(stack_a, stack_b);
		reverse_rotations(stack_a, rotations);
	}
}

void	merge(t_stack *stack_a, t_stack *stack_b)
{
	int		rotations;

	rotations = 0;
	while (stack_b->size > 0)
	{
		handle_rotations(stack_a, stack_b, &rotations);
		reverse_rotations(stack_a, &rotations);
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (cmp(current, current->next) > 0)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
	{
		sort_small_stack(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size >= 6)
	{
		sort_large_stack(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size <= 1 || is_sorted(stack_a))
		return (stack_a);
	split(stack_a, stack_b);
	merge_sort(stack_a, stack_b);
	merge(stack_a, stack_b);
	return (stack_a);
}
