/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:13:24 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 14:58:18 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void fill_stack_from_args(t_stack *stack, char **args)
{
	t_node *new_node;
// Error Handling for Invalid Input
// Duplicate Detection

	while (*args)
	{
		new_node = create_node(ft_atoi(*args));
		push_bottom(stack, new_node);
		args++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_args;
	char	**temp;

	stack_a = create_stack();
	stack_b = create_stack();
	// stack_b->top = stack_a->top;
	// stack_b->top = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		fill_stack_from_args(stack_a, split_args);
		temp = split_args;
		while (*split_args)
			free(*split_args++);
		free(temp);
	}
	else
	{
		fill_stack_from_args(stack_a, argv + 1);
	}
	// print_stack(stack_a);
	// bubble_sort(stack_a);
	merge_sort(stack_a, stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
