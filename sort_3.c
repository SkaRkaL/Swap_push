#include "push_swap.h"

void	sort_III(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 3)
	{
		int min;
		if (max_min_element(*stack_a, &min) == 1)
		{
			min_3(stack_a, min);
		}
		else if (max_min_element(*stack_a, &min) == 2)
		{
			min_1(stack_a, min);
		}
		else if (max_min_element(*stack_a, &min) == 3)
		{
			min_2(stack_a, min);
		}
	}
	else
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, ft_lstsize(*stack_a));
	}
}
