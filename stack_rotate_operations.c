/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:51:43 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/06 15:50:25 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack->size == 2)
	{
		stack->bottom = stack->top;
		stack->top = temp;
		stack->top->next = stack->bottom;
		stack->top->prev = NULL;
		stack->bottom->next = NULL;
		stack->bottom->prev = stack->top;
		return ;
	}
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
	if (stack->size < 2)
		return ;
	rotate(stack);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	rotate(stack);
	ft_printf("rb\n");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
