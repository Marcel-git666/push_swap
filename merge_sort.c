/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:29:02 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/08 22:11:08 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int find_min_value(t_stack *stack)
{
    t_node *current = stack->top;
    int min_value = current->value;

    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
        }
        current = current->next;
    }

    return min_value;
}

int find_max_value(t_stack *stack)
{
    t_node *current = stack->top;
    int max_value = current->value;

    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
        }
        current = current->next;
    }

    return max_value;
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

void sort_three_elements_b(t_stack *stack_b)
{
    int first = stack_b->top->value;
    int second = stack_b->top->next->value;
    int third = stack_b->top->next->next->value;

    if (first > second && second > third)
    {
        swap_b(stack_b);
        rev_rotate_b(stack_b);
    }
    else if (first > third && third > second)
    {
        rotate_b(stack_b);
    }
    else if (second > third && third > first)
    {
        swap_b(stack_b);
        rotate_b(stack_b);
    }
    else if (second > first && first > third)
    {
        rev_rotate_b(stack_b);
    }
    else if (third > first && first > second)
    {
        swap_b(stack_b);
    }
}

void push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current = stack_a->top;
    t_node *smallest = current;
    int position = 0;
    int smallest_position = 0;

    // Find the smallest element in stack_a
    while (current != NULL)
    {
        if (current->value < smallest->value)
        {
            smallest = current;
            smallest_position = position;
        }
        position++;
        current = current->next;
    }

    // Rotate to bring the smallest to the top
    if (smallest_position <= stack_a->size / 2)
    {
        while (smallest_position > 0)
        {
            rotate_a(stack_a);
            smallest_position--;
        }
    }
    else
    {
        while (smallest_position < stack_a->size)
        {
            rev_rotate_a(stack_a);
            smallest_position++;
        }
    }

    // Push the smallest element to stack_b
    push_b(stack_b, stack_a);
}
void move_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int min_val, int max_val)
{
    t_node *current;
    int position, chunk_position;
    int rotations;

    // Loop until no more elements in the chunk
    while (1)
    {
        current = stack_a->top;
        position = 0;
        chunk_position = -1;

        // Find the position of the first element in the chunk
        while (current)
        {
            if (current->value >= min_val && current->value <= max_val)
            {
                chunk_position = position;
                break;
            }
            position++;
            current = current->next;
        }

        // No more elements in the chunk
        if (chunk_position == -1)
            break;

        // Rotate to bring the chunk element to the top efficiently
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

        // Push the element from stack_a to stack_b
        push_b(stack_b, stack_a);
    }
}

void handle_five_elements(t_stack *stack_a, t_stack *stack_b)
{
    // Push the smallest two elements to stack_b
	push_smallest_to_b(stack_a, stack_b);  // Push one smallest
	push_smallest_to_b(stack_a, stack_b);  // Push another smallest

    // Sort the remaining 3 elements in stack_a
	sort_three_elements(stack_a);

    // Push back the two elements from stack_b
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
void push_max_to_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current = stack_b->top;
    t_node *largest = current;
    int position = 0;
    int largest_position = 0;

    // Find the largest element in stack_b
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

    // Rotate to bring the largest to the top
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

    // Push the largest element to stack_a
    push_a(stack_a, stack_b);
}


void sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
    int total_size = stack_a->size;
    int chunk_count;

    // Dynamically determine chunk count based on the size of stack_a
    if (total_size <= 150)
    {
        chunk_count = 5;  // For smaller stacks, split into 5 chunks
    }
    else
    {
        chunk_count = 12;  // For larger stacks, split into 12 chunks
    }

    int min_value = find_min_value(stack_a);
    int max_value = find_max_value(stack_a);

    // Process each chunk
    for (int i = 0; i < chunk_count; i++)
    {
        int lower_bound = min_value + i * (max_value - min_value) / chunk_count;
        int upper_bound = min_value + (i + 1) * (max_value - min_value) / chunk_count;

        // Move elements in this range to stack_b
        move_chunk_to_b(stack_a, stack_b, lower_bound, upper_bound);

        // For small remaining stacks in stack_a, use optimized sorting
        if (stack_a->size <= 5)
        {
            if (stack_a->size == 2)
                sort_two_elements(stack_a);
            else if (stack_a->size == 3)
                sort_three_elements(stack_a);
            else if (stack_a->size == 5)
                handle_five_elements(stack_a, stack_b);
        }
    }

    // Push elements back from stack_b to stack_a in sorted order
    while (stack_b->size > 0)
    {
        push_max_to_a(stack_a, stack_b);
    }
}



int cmp(t_node *a, t_node *b)
{
	if (a == NULL || b == NULL)
		return (0);
	if (a->value < b->value)
		return (-1);
	if (a->value > b->value)
		return (+1);
	return (0);
}

void	merge(t_stack *stack_a, t_stack *stack_b)
{
	int		rotations;

	rotations = 0;
	if (stack_b->size == 2)
		sort_two_elements_b(stack_b);
	else if (stack_b->size == 3)
		sort_three_elements_b(stack_b);
	while (stack_b->size > 0)
	{
		if (cmp(stack_b->top, stack_a->top) < 0)
		{
			push_a(stack_a, stack_b);
			while (rotations > 0)
			{
				rev_rotate_a(stack_a);
				rotations--;
			}
		}
		else
		{
			rotate_a(stack_a);
			rotations++;
			if (rotations == stack_a->size)
			{
				push_a(stack_a, stack_b);
				while (rotations > 0)
				{
					rev_rotate_a(stack_a);
					rotations--;
				}
			}
		}
	}
	while (rotations > 0)
	{
		rev_rotate_a(stack_a);
		rotations--;
	}
}


int is_sorted(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	while (current && current->next)
	{
		if (cmp(current, current->next) > 0)
			return (0);
		current = current->next;
	}
	return (1);
}

void split(t_stack *stack_a, t_stack *stack_b)
{
	int mid;
	int i;

	i = 0;
	mid = (stack_a->size + 1) / 2;
	while (i < mid)
	{
		// ft_printf("Moving to B: %d\n", stack_a->top->value);
		push_b(stack_b, stack_a);
		i++;
	}
}

t_stack *merge_sort(t_stack *stack_a, t_stack *stack_b)
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
	if (stack_a->size == 5)
	{
		handle_five_elements(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size >= 50)
	{
		sort_large_stack(stack_a, stack_b);
		return (stack_a);
	}
	if (stack_a->size <= 1 || is_sorted(stack_a))
	{
		// ft_printf("Base case reached, returning stack:\n");
		print_stack(stack_a);
		return (stack_a);
	}
	// ft_printf("Splitting stack:\n");
	// print_stack(stack_a);
	split(stack_a, stack_b);
	// ft_printf("After splitting A and B:\n");
	// print_stack(stack_a);
	// print_stack(stack_b);
	// ft_printf("Recursively sorting stack A:\n");
	merge_sort(stack_a, stack_b);
	// if (stack_b->size > 1) // Only sort stack_b if it has more than 1 element
	// {
	// 	ft_printf("Recursively sorting stack B:\n");
	// 	merge_sort(stack_b, stack_a);
	// }
	// ft_printf("Stack A size: %d, Stack B size: %d\n", stack_a->size, stack_b->size);
	// ft_printf("Merging stack A and B:\n");
	merge(stack_a, stack_b);
	// ft_printf("After merging A and B:\n");
	// print_stack(stack_a);
	// print_stack(stack_b);
	return (stack_a);
}
