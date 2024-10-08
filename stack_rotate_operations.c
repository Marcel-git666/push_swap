/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:51:43 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/07 17:27:07 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	stack->top = temp->next;
	stack->top->prev = NULL;
	temp->prev = stack->bottom;
	stack->bottom->next = temp;
	stack->bottom = temp;
	temp->next = NULL;
}

void	rotate_a(t_stack *stack)
{
	if (stack->size >= 2)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stack *stack)
{
	if (stack->size >= 2)
	{
		rotate(stack);
		ft_printf("rb\n");
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	int		rotated_a;
	int		rotated_b;

	rotated_a = 0;
	rotated_b = 0;
	if (stack_a->size >= 2)
	{
		rotate(stack_a);
		rotated_a = 1;
	}
	if (stack_b->size >= 2)
	{
		rotate(stack_b);
		rotated_b = 1;
	}
	if (rotated_a || rotated_b)
		ft_printf("rr\n");
}
