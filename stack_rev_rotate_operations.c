/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:15:59 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/07 17:29:51 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rev_rotate(t_stack *stack)
{
	t_node	*temp;

	temp = stack->bottom;
	stack->bottom = temp->prev;
	stack->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = stack->top;
	stack->top->prev = temp;
	stack->top = temp;
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
	int		rotated_a;
	int		rotated_b;

	rotated_a = 0;
	rotated_b = 0;
	if (stack_a->size >= 2)
	{
		rev_rotate(stack_a);
		rotated_a = 1;
	}
	if (stack_b->size >= 2)
	{
		rev_rotate(stack_b);
		rotated_b = 1;
	}
	if (rotated_a || rotated_b)
		ft_printf("rr\n");
}
