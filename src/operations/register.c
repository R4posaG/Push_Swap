/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:29:55 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/14 21:29:56 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Regista o movimento na struct e imprime no stdout (11 linhas)
void	regist_operation(t_program *program, t_op op_type, char *op_str)
{
	program->op_counts[op_type]++;
	program->total_ops++;
	ft_putstr_fd(op_str, 1);
}
