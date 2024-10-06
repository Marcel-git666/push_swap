/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:15:59 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/06 15:50:40 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rev_rotate(t_stack *stack)
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
	temp = stack->bottom;
	stack->bottom = temp->prev;
	stack->bottom->next = NULL;
	temp->next = stack->top;
	stack->top->prev = temp;
	stack->top = temp;
	temp->prev = NULL;
}

void	rev_rotate_a(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	rev_rotate(stack);
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	rev_rotate(stack);
	ft_printf("rrb\n");
}

void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
