/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_handling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 07:49:01 by mmravec           #+#    #+#             */
/*   Updated: 2024/10/10 08:06:51 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_atoi_safe(const char *str, int *error)
{
	long	result;
	int		positive;

	positive = 1;
	result = 0;
	*error = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((result * positive) > I_MAX ||
			(result * positive) < I_MIN)
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(result * positive));
}
