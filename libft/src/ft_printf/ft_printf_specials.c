/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specials.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:21:09 by hjacinto          #+#    #+#             */
/*   Updated: 2026/07/02 21:01:09 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_unsigned(unsigned int num, int *len)
{
	if (num > 9)
		print_unsigned(num / 10, len);
	print_char((num % 10) + '0', len);
}

void	print_hex(uintptr_t num, int *len, char *base)
{
	if (num >= 16)
		print_hex(num / 16, len, base);
	print_char(base[num % 16], len);
}

void	print_ptr(uintptr_t	addr, int *len)
{
	if (!addr)
	{
		print_str("(nil)", len);
		return ;
	}
	print_str("0x", len);
	print_hex(addr, len, "0123456789abcdef");
}
