/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:30:22 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/04 21:33:25 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

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

#endif
