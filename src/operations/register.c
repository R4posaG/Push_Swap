#include "push_swap.h"

// Regista o movimento na struct e imprime no stdout (11 linhas)
void	regist_operation(t_program *program, t_op op_type, char *op_str)
{
	program->op_counts[op_type]++;
	program->total_ops++;
	write(1, op_str, 3 + (op_str[3] == '\n'));
}