/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:36:23 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 20:26:42 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap_two_nodes(t_stack *stack_a, int rotations)
{
	int		i;

	i = 0;
	while (i < rotations && stack_a->top != stack_a->bottom)
	{
		rotate_a(stack_a);
		i++;
	}
	if (stack_a->top && stack_a->top->next
		&& stack_a->top->value > stack_a->top->next->value)
		swap_a(stack_a);
	while (i > 0)
	{
		rev_rotate_a(stack_a);
		i--;
	}
}

void	bubble_sort(t_stack *stack_a)
{
	int		swapped;
	int		i;
	t_node	*current_node;

	if (stack_a->size < 2)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		current_node = stack_a->top;
		while (i < stack_a->size - 1 && current_node != stack_a->bottom)
		{
			if (current_node->value > current_node->next->value)
			{
				swap_two_nodes(stack_a, i);
				swapped = 1;
				current_node = stack_a->top;
				i = 0;
			}
			current_node = current_node->next;
			i++;
		}
	}
}
