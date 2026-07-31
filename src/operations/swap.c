#include "../push_swap.h"

static void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
	second->prev = NULL;
	if (first->next)
        first->next->prev = first;
    second->next = first;
	first->prev = second;
    *stack = second;
}

void sa(t_program *program)
{
    swap(&program->stack_a);
    write(1, "sa\n", 3);
}

void sb(t_program *program)
{
    swap(&program->stack_b);
    write(1, "sb\n", 3);
}

void ss(t_program *program)
{
    swap(&program->stack_a);
    swap(&program->stack_b);
    write(1, "ss\n", 3);
}