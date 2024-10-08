/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:38:52 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/07 17:44:49 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = first->next;
	if (second == stack->bottom)
		stack->bottom = first;
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	stack->top = second;
}

void	swap_a(t_stack *stack)
{
	if (stack->size >= 2)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}

void	swap_b(t_stack *stack)
{
	if (stack->size >= 2)
	{
		swap(stack);
		ft_printf("sb\n");
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	int		swapped_a;
	int		swapped_b;

	swapped_a = 0;
	swapped_b = 0;
	if (stack_a->size >= 2)
	{
		swap(stack_a);
		swapped_a = 1;
	}
	if (stack_b->size >= 2)
	{
		swap(stack_b);
		swapped_b = 1;
	}
	if (swapped_a || swapped_b)
		ft_printf("ss\n");
}

