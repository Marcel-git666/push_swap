/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:47:17 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/06 14:55:57 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	t_node	*pushed;

	if (stack_b->size < 1)
		return ;
	pushed = stack_b->top;
	push_top(stack_a, pushed);
	stack_b->top = stack_b->top->next;
	if (stack_b->top != NULL)
		stack_b->top->prev = NULL;
	else
		stack_b->bottom = NULL;
	pushed->next = NULL;
	pushed->prev = NULL;
	stack_b->size--;
	ft_printf("%s\n", operation);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b, "pa");
}

void	push_b(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a, "pb");
}
