/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:05:54 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/08 18:05:54 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flags(int argc, char **argv, t_program *program)
{
	return (ft_strcmp(argv[1], "--Complex") || ft_strcmp(argv[1], "--Simple") 
		|| ft_strcmp(argv[1], "--Medium") || ft_strcmp(argv[1], "--Adaptive"));
}

void	read_flags(int argc, char **argv, t_program *program)
{
		if (ft_strcmp(argv[1], "--simple"))
			program->strategy = SIMPLE;
		else if (ft_strcmp(argv[1], "--medium"))
			program->strategy = MEDIUM;
		else if (ft_strcmp(argv[1], "--complex"))
			program->strategy = COMPLEX;
		else
			program->strategy = ADAPTIVE;
}
