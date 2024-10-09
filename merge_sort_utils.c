/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:48:08 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 16:49:55 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	find_min_value(t_stack *stack)
{
	t_node	*current;
	int		min_value;

	current = stack->top;
	min_value = current->value;
	while (current != NULL)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

int	find_max_value(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	current = stack->top;
	max_value = current->value;
	while (current != NULL)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	cmp(t_node *a, t_node *b)
{
	if (a == NULL || b == NULL)
		return (0);
	if (a->value < b->value)
		return (-1);
	if (a->value > b->value)
		return (+1);
	return (0);
}

void	reverse_rotations(t_stack *stack_a, int *rotations)
{
	while (*rotations > 0)
	{
		rev_rotate_a(stack_a);
		(*rotations)--;
	}
}

void	rotate_to_position(t_stack *stack_a, int position)
{
	if (position <= stack_a->size / 2)
	{
		while (position-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		while (position++ < stack_a->size)
			rev_rotate_a(stack_a);
	}
}
