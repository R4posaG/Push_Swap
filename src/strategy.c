/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:29:07 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/14 21:29:08 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_strategy(t_program *program)
{
	double	disorder;

	disorder = subject_disorder(&program->stack_a);
	program->disorder = disorder * 100.0;
	if (program->strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			sort_simple(program);
		else if (disorder < 0.5)
			sort_medium(program);
		else
			sort_complex(program);
	}
	else if (program->strategy == SIMPLE)
		sort_simple(program);
	else if (program->strategy == MEDIUM)
		sort_medium(program);
	else if (program->strategy == COMPLEX)
		sort_complex(program);
}
