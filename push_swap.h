/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:30:22 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/10 08:06:58 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define I_MIN -2147483648
# define I_MAX 2147483647

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}		t_stack;

t_node	*create_node(int value);
t_stack	*create_stack(void);
void	push_bottom(t_stack *stack_a, t_node *new_node);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push_top(t_stack *stack, t_node *new_node);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_a(t_stack *stack);
void	rev_rotate_b(t_stack *stack);
void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	bubble_sort(t_stack *stack_a);
t_stack	*merge_sort(t_stack *stack_a, t_stack *stack_b);
void	quicksort_push_swap(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);
int		find_min_value(t_stack *stack);
int		find_max_value(t_stack *stack);
void	sort_two_elements_b(t_stack *stack_b);
void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_four_elements(t_stack *stack_a, t_stack *stack_b);
void	sort_five_elements(t_stack *stack_a, t_stack *stack_b);
int		find_smallest_position(t_stack *stack_a, int smallest_value);
void	rotate_to_position(t_stack *stack_a, int position);
int		find_chunk_position(t_stack *stack_a, int min_val, int max_val);
void	move_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int min_val,
			int max_val);
int		find_largest_position(t_stack *stack_b, t_node **largest);
void	push_max_to_a(t_stack *stack_a, t_stack *stack_b);
void	process_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_count);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_large_stack(t_stack *stack_a, t_stack *stack_b);
int		cmp(t_node *a, t_node *b);
void	reverse_rotations(t_stack *stack_a, int *rotations);
void	handle_rotations(t_stack *stack_a, t_stack *stack_b, int *rotations);
void	merge(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
void	split(t_stack *stack_a, t_stack *stack_b);
t_stack	*merge_sort(t_stack *stack_a, t_stack *stack_b);

#endif
