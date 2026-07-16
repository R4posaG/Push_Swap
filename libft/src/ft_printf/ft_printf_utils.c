/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:29:20 by hjacinto          #+#    #+#             */
/*   Updated: 2026/07/02 21:51:13 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_error(int size)
{
	static int	error = 0;

	if (size == -2)
		error = 0;
	if (size == -1)
		error = 1;
	return (error);
}

void	print_char(char c, int *len)
{
	int	temp;

	if (get_error(0))
		return ;
	temp = write(1, &c, 1);
	if (get_error(temp))
		return ;
	(*len)++;
}

void	print_str(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		print_char(str[i], len);
		i++;
	}
}

void	print_num(int num, int *len)
{
	long	n;

	n = num;
	if (n < 0)
	{
		print_char('-', len);
		n = -n;
	}
	if (n > 9)
		print_num(n / 10, len);
	print_char((n % 10) + '0', len);
}
