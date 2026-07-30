#include "../push_swap.h"

static void push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;

    if (!src || !*src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    if (*src)
		(*src)->prev = NULL;
    tmp->next = *dest;
	if (*dest)
		*dest->prev = tmp;
    *dest = tmp;
	temp->prev = NULL;
}

void pa(t_program *program)
{
    push(&program->stack_b, &program->stack_a);
	pg->size_a++;
    pg->size_b--;
    write(1, "pa\n", 3);
}

void pb(t_program *program)
{
    push(&program->stack_a, &program->stack_b);
	pg->size_a--;
    pg->size_b++;
    write(1, "pb\n", 3);
}
