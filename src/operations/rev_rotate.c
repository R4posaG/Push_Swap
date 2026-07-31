#include "../push_swap.h"

static void rev_rotate(t_stack **stack)
{
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	if (last->prev)
        last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
	}

void rra(t_program *program)
{
	if (!pg || !pg->stack_a || !pg->stack_a->next)
        return ;
    rev_rotate(&pg->stack_a);
    write(1, "rra\n", 4);
}

void rrb(t_program *program)
{
	if (!pg || !pg->stack_b || !pg->stack_b->next)
        return ;
    rev_rotate(&pg->stack_b);
    write(1, "rrb\n", 4);
}

void rrr(t_program *program)
{
    if (!pg)
        return ;
    rev_rotate(&pg->stack_a);
    rev_rotate(&pg->stack_b);
    write(1, "rrr\n", 4);
}
