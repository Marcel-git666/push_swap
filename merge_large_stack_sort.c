/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_large_stack_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:47:00 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 20:23:50 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	move_chunk_to_b(t_stack *stack_a, t_stack *stack_b,
	int min_val, int max_val)
{
	int		chunk_position;

	while (1)
	{
		chunk_position = find_chunk_position(stack_a, min_val, max_val);
		if (chunk_position == -1)
			break ;
		rotate_to_position(stack_a, chunk_position);
		push_b(stack_b, stack_a);
	}
}

void	process_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_count)
{
	int		i;
	int		lower_bound;
	int		upper_bound;
	int		min_value;
	int		max_value;

	min_value = find_min_value(stack_a);
	max_value = find_max_value(stack_a);
	i = 0;
	while (i < chunk_count)
	{
		lower_bound = min_value + i * (max_value - min_value) / chunk_count;
		upper_bound = min_value + (i + 1) * (max_value - min_value)
			/ chunk_count;
		move_chunk_to_b(stack_a, stack_b, lower_bound, upper_bound);
		i++;
	}
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two_elements(stack_a);
	else if (stack_a->size == 3)
		sort_three_elements(stack_a);
	else if (stack_a->size == 4)
		sort_four_elements(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five_elements(stack_a, stack_b);
}

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		total_size;
	int		chunk_count;

	total_size = stack_a->size;
	if (total_size <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	process_chunks(stack_a, stack_b, chunk_count);
	if (stack_a->size <= 5)
		sort_small_stack(stack_a, stack_b);
	while (stack_b->size > 0)
		push_max_to_a(stack_a, stack_b);
}

void	push_max_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*largest;
	int		largest_position;

	largest_position = find_largest_position(stack_b, &largest);
	if (largest_position <= stack_b->size / 2)
		while (largest_position-- > 0)
			rotate_b(stack_b);
	else
		while (largest_position++ < stack_b->size)
			rev_rotate_b(stack_b);
	push_a(stack_a, stack_b);
}
