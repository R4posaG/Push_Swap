#include "push_swap.h"

// Cria um novo node na memória com os ponteiros inicializados a NULL
static t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1; // Inicializado a -1 até ser calculado
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	stack_add_back(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack *current;

	new_node = create_node(value);
	if (!node)
	{
		node->prev = NULL;
		*stack = node;
		return ;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}
