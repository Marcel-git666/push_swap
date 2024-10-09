/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stack_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:49:53 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 20:23:18 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	find_smallest_position(t_stack *stack_a, int smallest_value)
{
	t_node	*current;
	int		position;
	int		smallest_position;

	current = stack_a->top;
	position = 0;
	smallest_position = 0;
	while (current != NULL)
	{
		if (current->value == smallest_value)
		{
			smallest_position = position;
			break ;
		}
		position++;
		current = current->next;
	}
	return (smallest_position);
}

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		smallest_value;
	int		smallest_position;

	smallest_value = find_min_value(stack_a);
	smallest_position = find_smallest_position(stack_a, smallest_value);
	if (smallest_position <= stack_a->size / 2)
		while (smallest_position-- > 0)
			rotate_a(stack_a);
	else
		while (smallest_position++ < stack_a->size)
			rev_rotate_a(stack_a);
	push_b(stack_b, stack_a);
}

int	find_chunk_position(t_stack *stack_a, int min_val, int max_val)
{
	t_node	*current;
	int		position;

	current = stack_a->top;
	position = 0;
	while (current)
	{
		if (current->value >= min_val && current->value <= max_val)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	find_largest_position(t_stack *stack_b, t_node **largest)
{
	t_node	*current;
	int		position;
	int		largest_position;

	current = stack_b->top;
	*largest = current;
	position = 0;
	largest_position = 0;
	while (current != NULL)
	{
		if (current->value > (*largest)->value)
		{
			*largest = current;
			largest_position = position;
		}
		position++;
		current = current->next;
	}
	return (largest_position);
}

void	split(t_stack *stack_a, t_stack *stack_b)
{
	int		mid;
	int		i;

	i = 0;
	mid = (stack_a->size + 1) / 2;
	while (i < mid)
	{
		push_b(stack_b, stack_a);
		i++;
	}
}
