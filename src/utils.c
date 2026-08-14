/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:35:20 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/05 15:43:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_matrix(char **matrix)
{
	int i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	result;
	int		digit;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (sign == 1 && result > (LONG_MAX - digit) / 10)
			return (LONG_MAX);
		if (sign == -1 && result > (LONG_MAX - digit) / 10)
			return (LONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}