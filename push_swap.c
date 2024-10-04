/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:13:24 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/04 19:37:50 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*new_node;

	count = 1;
	stack_a = create_stack();
	stack_b = create_stack();

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		ft_printf("Argv [1]: %s\n", argv[1]);
	}
	else
	{
		while (count < argc)
		{
			new_node = create_node(ft_atoi(argv[count]));
			push_bottom(stack_a, new_node);
			count++;
		}
	}
	print_stack(stack_a);
	print_stack(stack_b);
	return (0);
}
