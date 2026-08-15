/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:35:20 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/15 12:25:15 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t					i;
	unsigned char			*str1;
	unsigned char			*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
