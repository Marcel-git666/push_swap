/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:29:02 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/09 15:02:11 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);

int	find_min_value(t_stack *stack)
{
	t_node	*current;
	int		min_value;

	current = stack->top;
	min_value = current->value;
	while (current != NULL)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

int	find_max_value(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	current = stack->top;
	max_value = current->value;
	while (current != NULL)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

void	sort_two_elements_b(t_stack *stack_b)
{
	if (stack_b->top->value > stack_b->top->next->value)
		swap_b(stack_b);
}

void	sort_two_elements(t_stack *stack)
{
	if (stack->top->value > stack->top->next->value)
		swap_a(stack);
}

void	sort_three_elements(t_stack *stack)
{
	int		top;
	int		middle;
	int		bottom;

	top = stack->top->value;
	middle = stack->top->next->value;
	bottom = stack->bottom->value;
	if (top > middle && middle < bottom && top < bottom)
		swap_a(stack);
	else if (top > middle && middle > bottom)
	{
		swap_a(stack);
		rev_rotate_a(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_a(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rev_rotate_a(stack);
}


void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	push_a(stack_a, stack_b);
}


void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		smallest_value;
	int		position;
	int		smallest_position;

	current = stack_a->top;
	smallest_value = find_min_value(stack_a);
	position = 0;
	smallest_position = 0;
	while (current != NULL)
	{
		if (current->value == smallest_value)
		{
			smallest_position = position;
			break ;
		}
		position++;
		current = current->next;
	}
	if (smallest_position <= stack_a->size / 2)
		while (smallest_position-- > 0)
			rotate_a(stack_a);
	else
		while (smallest_position++ < stack_a->size)
			rev_rotate_a(stack_a);
	push_b(stack_b, stack_a);
}

void	move_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int min_val, int max_val)
{
	t_node	*current;
	int		position;
	int		chunk_position;
	int		rotations;

	while (1)
	{
		current = stack_a->top;
		position = 0;
		chunk_position = -1;
		while (current)
		{
			if (current->value >= min_val && current->value <= max_val)
			{
				chunk_position = position;
				break ;
			}
			position++;
			current = current->next;
		}
		if (chunk_position == -1)
			break ;
		rotations = chunk_position;
		if (chunk_position <= stack_a->size / 2)
		{
			while (rotations-- > 0)
				rotate_a(stack_a);
		}
		else
		{
			rotations = stack_a->size - chunk_position;
			while (rotations-- > 0)
				rev_rotate_a(stack_a);
		}
		push_b(stack_b, stack_a);
	}
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	push_max_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*largest;
	int		position;
	int		largest_position;

	current = stack_b->top;
	largest = current;
	position = 0;
	largest_position = 0;
	while (current != NULL)
	{
		if (current->value > largest->value)
		{
			largest = current;
			largest_position = position;
		}
		position++;
		current = current->next;
	}
	if (largest_position <= stack_b->size / 2)
	{
		while (largest_position > 0)
		{
			rotate_b(stack_b);
			largest_position--;
		}
	}
	else
	{
		while (largest_position < stack_b->size)
		{
			rev_rotate_b(stack_b);
			largest_position++;
		}
	}
	push_a(stack_a, stack_b);
}

void process_chunks(t_stack *stack_a, t_stack *stack_b,
	int chunk_count, int min_value, int max_value)
{
	int		i;
	int		lower_bound;
	int		upper_bound;

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
	else if (stack_a->size == 5)
		sort_five_elements(stack_a, stack_b);
}


void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		total_size;
	int		chunk_count;
	int		min_value;
	int		max_value;

	total_size = stack_a->size;
	if (total_size <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	min_value = find_min_value(stack_a);
	max_value = find_max_value(stack_a);
	process_chunks(stack_a, stack_b, chunk_count, min_value, max_value);
	if (stack_a->size <= 5)
		sort_small_stack(stack_a, stack_b);
	while (stack_b->size > 0)
		push_max_to_a(stack_a, stack_b);
}

int	cmp(t_node *a, t_node *b)
{
	if (a == NULL || b == NULL)
		return (0);
	if (a->value < b->value)
		return (-1);
	if (a->value > b->value)
		return (+1);
	return (0);
}

void	reverse_rotations(t_stack *stack_a, int *rotations)
{
	while (*rotations > 0)
	{
		rev_rotate_a(stack_a);
		(*rotations)--;
	}
}

void	merge(t_stack *stack_a, t_stack *stack_b)
{
	int		rotations;

	rotations = 0;
	while (stack_b->size > 0)
	{
		if (cmp(stack_b->top, stack_a->top) < 0)
		{
			push_a(stack_a, stack_b);
			if (rotations > 0 && cmp(stack_a->top, stack_a->bottom) > 0)
				reverse_rotations(stack_a, &rotations);
		}
		else
		{
			rotate_a(stack_a);
			rotations++;
		}
		if (rotations == stack_a->size)
		{
			while (rotations > 0)
				reverse_rotations(stack_a, &rotations);
		}
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (cmp(current, current->next) > 0)
			return (0);
		current = current->next;
	}
	return (1);
}

void	split(t_stack *stack_a, t_stack *stack_b)
{
	int		mid;
	int		i;

	i = 0;
	mid = (stack_a->size + 1) / 2;
	while (i < mid)
	{
		push_b(stack_b, stack_a);
		i++;
	}
}

t_stack	*merge_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		sort_two_elements(stack_a);
		return (stack_a);
	}
	if (stack_a->size == 3)
	{
		sort_three_elements(stack_a);
		return (stack_a);
	}
	if (stack_a->size == 4)
	{
		sort_four_elements(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size == 5)
	{
		sort_five_elements(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size >= 6)
	{
		sort_large_stack(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size <= 1 || is_sorted(stack_a))
		return (stack_a);
	split(stack_a, stack_b);
	merge_sort(stack_a, stack_b);
	merge(stack_a, stack_b);
	return (stack_a);
}
