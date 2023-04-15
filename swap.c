#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	sa(t_list **stack, int index)
{
	swap(stack);
	if (index)
		write(1, "sa\n", 3);
	indx_stack(stack);
}

void	sb(t_list **stack, int index)
{
	swap(stack);
	if (index)
		write(1, "sb\n", 3);
	indx_stack(stack);
}

void	ss(t_list **stack_a, t_list **stack_b, int index)
{
	swap(stack_a);
	swap(stack_b);
	if (index)
		write(1, "ss\n", 3);
}