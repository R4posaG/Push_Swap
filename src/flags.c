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

#include "../push_swap.h"

int	check_flags(char *arg)
{
	return (ft_strcmp(arg, "--complex") == 0 || ft_strcmp(arg, "--simple") == 0 
		|| ft_strcmp(arg, "--medium") == 0 || ft_strcmp(arg, "--adaptive") == 0 
		|| ft_strcmp(arg, "--bench") == 0);
}

void	read_flags(char *arg, t_program *program)
{
		if (ft_strcmp(arg, "--bench") == 0)
			program->bench_mode = 1;
		else if (ft_strcmp(arg, "--simple") == 0)
			program->strategy = SIMPLE;
		else if (ft_strcmp(arg, "--medium") == 0)
			program->strategy = MEDIUM;
		else if (ft_strcmp(arg, "--complex") == 0)
			program->strategy = COMPLEX;
		else if (ft_strcmp(arg, "--adaptive") == 0)
			program->strategy = ADAPTIVE;
}

int	count_flags(int argc, char **argv)
{
	int	i;
 
	i = 1;
	while (i < argc && check_flags(argv[i]))
		i++;
	return (i - 1);
}
