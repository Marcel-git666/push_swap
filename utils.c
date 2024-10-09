/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:01:00 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 20:25:24 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	if (!new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		stack->bottom = new_node;
	}
	stack->size++;
}

void	push_top(t_stack *stack, t_node *new_node)
{
	if (!new_node)
		return ;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;
// 	int		i;

// 	i = 0;
// 	current = stack->top;
// 	if (stack->size == 0)
// 	{
// 		ft_printf("Stack is empty.\n");
// 		return ;
// 	}

// 	ft_printf("Stack (top to bottom):\n");
// 	while (current)
// 	{
// 		ft_printf("[%d]: %d\n", i, current->value);
// 		current = current->next;
// 		i++;
// 	}
// }
