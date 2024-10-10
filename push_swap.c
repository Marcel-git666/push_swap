/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:13:24 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/10 08:01:36 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	search_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL )
	{
		if (value == current->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	fill_stack_from_args(t_stack *stack, char **args)
{
	t_node	*new_node;
	int		value;
	int		error;

	while (*args)
	{
		value = ft_atoi_safe(*args, &error);
		if (error)
			return (ft_putstr_fd("Error\n", 2), 0);
		if (search_duplicate(stack, value))
			return (ft_putstr_fd("Error\n", 2), 0);
		new_node = create_node(value);
		if (!new_node)
			return (0);
		push_bottom(stack, new_node);
		args++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_args;

	stack_a = create_stack();
	stack_b = create_stack();
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			return (1);
		if (!fill_stack_from_args(stack_a, split_args))
		{
			while (*split_args)
				free(*split_args++);
			free_stack(stack_a);
			free_stack(stack_b);
			return (1);
		}
		while (*split_args)
			free(*split_args++);
	}
	else
	{
		if (!fill_stack_from_args(stack_a, argv + 1))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (1);
		}
	}
	merge_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
