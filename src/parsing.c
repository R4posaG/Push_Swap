/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:35:44 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/08 18:05:22 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int is_valid(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}	
	return (1);
}

static int process_argument(char *arg, t_program *program)
{
	long	num;
	t_stack	*new_node;

	if (!is_valid(arg))
		return (0);
	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (has_duplicate(program->stack_a, (int)num))
		return (0);
	new_node = create_node((int)num);
	if (!new_node)
		return (0);
	stack_add_back(&program->stack_a, new_node);
	program->size_a++;
	return (1);
}

int	parse_arguments(int argc, char **argv, t_program *program)
{
	int		i;
	int		j;
	char    **args;

	i = 1 + count_flags(argc, argv);
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
    	if (!args || !args[0])
        	return (free_matrix(args), 0);
		j = 0;
		while (args[j])
		{
			if (!process_argument(args[j], program))
				return (free_matrix(args), 0);
			j++;
		}
		free_matrix(args);
		i++;
	}
	return (1);
}
