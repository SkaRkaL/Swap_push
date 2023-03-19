#include "push_swap.h"

void	pb(t_list **stack_b, t_list **stack_a, int indx_b, int indx_a)
{
	t_list	*tmp;
	if (!indx_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (indx_a)
		puts("pb");
}

void	pa(t_list **stack_a, t_list **stack_b, int indx_a, int indx_b)
{
	t_list	*tmp;
	if (!indx_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (indx_a)
		puts("pa");
}
