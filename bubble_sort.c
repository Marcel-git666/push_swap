/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:36:23 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/06 16:39:01 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
    int swapped;
    int size;
    int i;

    size = stack_a->size;
    if (size < 2)
        return;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        i = 0;

        while (i < size - 1)
        {
            // Push two elements to stack_b
            push_b(stack_a, stack_b);
            push_b(stack_a, stack_b);

            // Debugging: Print comparison before swapping
            if (stack_b->top && stack_b->top->next)
            {
                ft_printf("Comparing %d and %d\n", stack_b->top->value, stack_b->top->next->value);
            }

            // Compare and possibly swap using swap_b
            if (stack_b->top && stack_b->top->next &&
                stack_b->top->value > stack_b->top->next->value)
            {
                swap_b(stack_b);
                swapped = 1;
            }

            // Push the sorted elements back to stack_a
            push_a(stack_a, stack_b);
            push_a(stack_a, stack_b);

            i++;
        }
    }
}

