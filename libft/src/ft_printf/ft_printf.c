/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:49:01 by hjacinto          #+#    #+#             */
/*   Updated: 2026/07/02 21:49:33 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	read_arguments(const char format, va_list args, int *len)
{
	if (format == 'c')
		print_char(va_arg(args, int), len);
	else if (format == 's')
		print_str(va_arg(args, char *), len);
	else if (format == 'd' || format == 'i')
		print_num(va_arg(args, int), len);
	else if (format == 'p')
		print_ptr((uintptr_t)va_arg(args, void *), len);
	else if (format == 'u')
		print_unsigned(va_arg(args, unsigned int), len);
	else if (format == 'x')
		print_hex(va_arg(args, unsigned int), len, "0123456789abcdef");
	else if (format == 'X')
		print_hex(va_arg(args, unsigned int), len, "0123456789ABCDEF");
	else if (format == '%')
		print_char('%', len);
	else
	{
		print_char('%', len);
		print_char(format, len);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!format)
		return (-1);
	(void)get_error(-2);
	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] && !get_error(0))
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			read_arguments(format[++i], args, &len);
		else if (format[i] != '%')
			print_char(format[i], &len);
		else
			get_error(-1);
		i++;
	}
	va_end(args);
	if (get_error(0))
		return (-1);
	return (len);
}
