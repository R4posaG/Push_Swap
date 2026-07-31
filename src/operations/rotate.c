#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	}

void ra(t_program *program)
{
    rotate(&program->stack_a);
    write(1, "ra\n", 3);
}

void rb(t_program *program)
{
    rotate(&program->stack_b);
    write(1, "rb\n", 3);
}

void rr(t_program *program)
{
    rotate(&program->stack_a);
    rotate(&program->stack_b);
    write(1, "rr\n", 3);
}