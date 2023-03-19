#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list *tmp;

	tmp = ft_beforelast((*stack));
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
}

void	rra(t_list **stack_a, int index)
{
	reverse_rotate(stack_a);
	if(index)
		puts("rra");
}

void	rrb(t_list **stack_b, int index)
{
	reverse_rotate(stack_b);
	if(index)
		puts("rra");
}

void	rrr(t_list **stack_a, t_list **stack_b, int index)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (index)
		puts("rrr");
}
