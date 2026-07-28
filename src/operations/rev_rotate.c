#include "../push_swap.h"

static void rev_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_to_last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    
    last = *stack;
    second_to_last = NULL;
    
    while (last->next != NULL)
    {
        second_to_last = last;
        last = last->next;
    }
    
    second_to_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **a)
{
    rev_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    rev_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    write(1, "rrr\n", 4);
}