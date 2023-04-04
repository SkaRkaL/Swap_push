#include "push_swap.h"

void fun1(t_list **stack_a, t_list **stack_b, t_list *test, int a)
{
	while(1)
	{
		if((*stack_a)->content == test -> content)
			break;
		if(a == 0)
			rra(stack_a, ft_lstsize(*stack_a));
		if(a == 1)
			ra(stack_a, ft_lstsize(*stack_a));
	}
	pb(stack_b, stack_a, ft_lstsize(*stack_a));
}

int fun(t_list *stack, t_list *elem)
{
	int kk = 0;
	t_list *test = stack;
	int size = ft_lstsize(stack);
	while (1)
	{
		if(elem -> content == test -> content)
				break ;
		test = test -> next;
		kk++;
	}

	if(kk > size/2)
		return 0;
	return 1;
}

void	push_flag0_b(t_list **stack_a, t_list **stack_b)
{
	int	re_think;
	t_list *tmp = *stack_a;
	while(tmp)
	{
		re_think = 0;
		if(tmp -> flag == 0)
		{
			int a = fun((*stack_a), tmp);
			fun1(stack_a, stack_b, tmp, a);
			tmp = *stack_a;
			re_think = 1;
		}
		if(re_think == 0)
			tmp = tmp -> next;
	}
}