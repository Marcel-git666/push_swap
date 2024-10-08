/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:29:02 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/08 16:30:47 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void sort_two_elements_b(t_stack *stack_b)
{
    if (stack_b->top->value > stack_b->top->next->value)
        swap_b(stack_b);  // Swap if the first element is greater than the second
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

void sort_three_elements(t_stack *stack)
{
    int top = stack->top->value;
    int middle = stack->top->next->value;
    int bottom = stack->bottom->value;

    if (top > middle && middle < bottom && top < bottom) {
        // Case where top > middle < bottom, but top < bottom
        swap_a(stack);
    }
    else if (top > middle && middle > bottom) {
        // Case where top > middle > bottom (reverse sorted)
        swap_a(stack);
        rev_rotate_a(stack);
    }
    else if (top > middle && middle < bottom && top > bottom) {
        // Case where top > middle < bottom, and top > bottom
        rotate_a(stack);
    }
    else if (top < middle && middle > bottom && top < bottom) {
        // Case where top < middle > bottom, but top < bottom
        swap_a(stack);
        rotate_a(stack);
    }
    else if (top < middle && middle > bottom && top > bottom) {
        // Case where top < middle > bottom and top > bottom
        rev_rotate_a(stack);
    }
    // If the stack is already sorted, do nothing.
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

void merge(t_stack *stack_a, t_stack *stack_b)
{
	int rotations = 0;

	if (stack_b->size == 2)
    {
        sort_two_elements_b(stack_b); // This function will sort stack_b with 2 elements
    }
    else if (stack_b->size == 3)
    {
        sort_three_elements_b(stack_b); // This function will sort stack_b with 3 elements
    }
	while (stack_b->size > 0)
	{
		// ft_printf("Comparing A: %d, B: %d\n", stack_a->top->value, stack_b->top->value);
		if (cmp(stack_b->top, stack_a->top) < 0)
		{
			// ft_printf("Pushing from B to A: %d\n", stack_b->top->value);
			push_a(stack_a, stack_b);
			while (rotations > 0)
			{
				// ft_printf("Reversing rotation: A: %d\n", stack_a->top->value);
				rev_rotate_a(stack_a);
				rotations--;
			}
		}
		else
		{
			// ft_printf("Rotating A: %d\n", stack_a->top->value);
			rotate_a(stack_a);
			rotations++;
			if (rotations == stack_a->size)
			{
				// ft_printf("Pushing from B to A after full rotation: %d\n", stack_b->top->value);
				push_a(stack_a, stack_b);
				while (rotations > 0)
				{
					// ft_printf("Reversing rotation after push: A: %d\n", stack_a->top->value);
					rev_rotate_a(stack_a);
					rotations--;
				}
			}
		}
	}
	while (rotations > 0)
	{
		// ft_printf("Final reverse rotation: A: %d\n", stack_a->top->value);
		rev_rotate_a(stack_a);
		rotations--;
	}
}

void sort_two_elements(t_stack *stack)
{
	if (stack->size == 2 && stack->top->value > stack->top->next->value)
	{
		swap_a(stack); // Assuming swap_a swaps the top two elements of stack_a
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
        return stack_a;
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
