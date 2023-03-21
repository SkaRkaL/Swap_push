#include "push_swap.h"

void	sort_III(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 3)
	{
		int min;
		if(max_min_element(*stack_a, &min) == 1)
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
		else if(max_min_element(*stack_a, &min) == 2)
		{
			if (min == 1)
			{
				sa(stack_a, ft_lstsize(*stack_a));
				ra(stack_a, ft_lstsize(*stack_a));
			}
			else
				rra(stack_a, ft_lstsize(*stack_a));
		}
		else if(max_min_element(*stack_a, &min) == 3)
		{
			if (min == 2)
				sa(stack_a, ft_lstsize(*stack_a));
		}
	}
	else
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, ft_lstsize(*stack_a));
	}
}

void	sort_V(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) <= 5)
	{
		int min;
		max_min_element(*stack_a, &min);
		while (min > 1)
		{
			ra(stack_a, ft_lstsize(*stack_a));
			min--;
		}
		pb(stack_b, stack_a, ft_lstsize(*stack_a));
		max_min_element(*stack_a, &min);
		while (min > 1)
		{
			ra(stack_a, ft_lstsize(*stack_a));
			min--;
		}
		pb(stack_b, stack_a, ft_lstsize(*stack_a));
		sort_III(stack_a);
		pa(stack_a, stack_b, ft_lstsize(*stack_b));		
		pa(stack_a, stack_b, ft_lstsize(*stack_b));
	}
}
