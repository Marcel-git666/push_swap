/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:47:17 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/08 09:40:41 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pushed;

	if (stack_b->size < 1)
		return ;
	pushed = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (stack_b->top)
		stack_b->top->prev = NULL;
	else
		stack_b->bottom = NULL;
	pushed->next = NULL;
	pushed->prev = NULL;
	push_top(stack_a, pushed);
	stack_b->size--;
	stack_a->size++;
	ft_printf("pa\n");
}

void	push_b(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*pushed;

	if (stack_a->size < 1)
		return ;
	pushed = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (stack_a->top)
		stack_a->top->prev = NULL;
	else
		stack_a->bottom = NULL;
	pushed->next = NULL;
	pushed->prev = NULL;
	push_top(stack_b, pushed);
	stack_a->size--;
	stack_b->size++;
	ft_printf("pb\n");
}

