#include "push_swap.h"

// Cria um novo node na memória com os ponteiros inicializados a NULL
t_stack	*stack_new(int value)
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
