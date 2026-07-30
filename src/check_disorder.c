double subject_disorder(t_stack **stack_a)
{
	int mistakes;
	int total_pairs;
	t_stack	*current;
	t_stack *next;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = *stack_a;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			total_pairs++;
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		current = current->next;
	}
	// Proteção contra divisão por zero (se já estiver ordenado a desordem é 0.0)
	if (total_pairs == 0 || mistakes == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
