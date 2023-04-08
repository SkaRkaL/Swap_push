#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_list **stack_a, int index)
{
	rotate(stack_a);
	if (index)
		puts("ra");
	indx_stack(stack_a);
}

void	rb(t_list **stack_b, int index)
{
	rotate(stack_b);
	if (index)
		puts("rb");
	indx_stack(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b, int index)
{
	rotate(stack_a);
	rotate(stack_b);
	if (index)
		puts("rr");
	indx_stack(stack_a);
}