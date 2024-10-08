/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:18 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/08 09:51:07 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void handle_two_elements(t_stack *stack)
{
	if (stack->size == 2 && stack->top->value > stack->top->next->value)
	{
		ft_printf("Swapping 2 elements: %d, %d\n", stack->top->value, stack->top->next->value);
		swap_a(stack);
	}
}

int	find_pivot(t_stack *stack)
{
	int median = stack->size / 2;
	t_node *current = stack->top;
	for (int i = 0; i < median; i++)
	{
		current = current->next;
	}
	return (current->value);
}

void quicksort_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	int		i;
	int		original_size;

	i = 0;
	if (stack_a->size == 2)
	{
		handle_two_elements(stack_a);
		return ;
	}
	if (stack_a->size <= 1)
		return ;
	pivot = find_pivot(stack_a);
	ft_printf("Using pivot: %d\n", pivot);
	original_size = stack_a->size;

	while (i < original_size && stack_a->size > 0)
	{
		if (stack_a->top->value < pivot)
		{
			ft_printf("Pushing to B: %d\n", stack_a->top->value);
			push_b(stack_b, stack_a);
		}
		else
		{
			ft_printf("Rotating A: %d\n", stack_a->top->value);
			rotate_a(stack_a);
		}
		i++;
	}
	ft_printf("Stack A after partition:\n");
	print_stack(stack_a);
	ft_printf("Stack B after partition:\n");
	print_stack(stack_b);
	// // Pause to allow for debugging
    // ft_printf("Press Enter to continue...\n");
    // getchar();  // Wait for Enter key to continue
	if (stack_a->size > 1 && !is_sorted(stack_a))
	{
		ft_printf("Recursively sorting stack A\n");
		quicksort_push_swap(stack_a, stack_b);
	}
	if (stack_b->size > 1 && !is_sorted(stack_b))
	{
		ft_printf("Recursively sorting stack B\n");
		quicksort_push_swap(stack_b, stack_a);
	}
	while (stack_b->size > 0)
	{
		if (stack_a->top && stack_b->top->value > stack_a->top->value)
		{
			ft_printf("Rotating A during merge: %d\n", stack_a->top->value);
			rotate_a(stack_a);
		}
		ft_printf("Pushing back to A from B\n");
		push_a(stack_a, stack_b);
	}
	ft_printf("Final Stack A:\n");
	print_stack(stack_a);
	ft_printf("Final Stack B:\n");
	print_stack(stack_b);
}
