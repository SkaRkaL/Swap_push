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
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack, int index)
{
	swap(stack);
	if (index)
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b, int index)
{
	swap(stack_a);
	swap(stack_b);
	if (index)
		ft_putendl_fd("ss", 1);
}