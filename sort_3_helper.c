#include "push_swap.h"

void	min_3(t_list **stack_a, int min)
{
	if (min == 3)
	{
		sa(stack_a, ft_lstsize(*stack_a));
		rra(stack_a, ft_lstsize(*stack_a));
	}
	else
	{
		ra(stack_a, ft_lstsize(*stack_a));
	}
}

void	min_1(t_list **stack_a, int min)
{
	if (min == 1)
	{
		sa(stack_a, ft_lstsize(*stack_a));
		ra(stack_a, ft_lstsize(*stack_a));
	}
	else
		rra(stack_a, ft_lstsize(*stack_a));
}

void	min_2(t_list **stack_a, int min)
{
	if (min == 2)
		sa(stack_a, ft_lstsize(*stack_a));
}
