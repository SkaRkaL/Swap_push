#include "push_swap.h"

void	mn_te7t_lfo9(t_list **stack_a, t_list *test, int a)
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
}

void fun1(t_list **stack_a, t_list **stack_b, t_list *test, int a)
{
	mn_te7t_lfo9(stack_a, test, a);
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

int best_moves(t_list *stack,t_list *elem)
{
	int i = 0;
	t_list *tmp = stack;
	int top_or_down = fun(stack,elem);
	if (top_or_down == 1)
	{
		while(tmp)
		{
			if (tmp->content == elem->content)
				break;
			i++;
			tmp = tmp->next;
		}
		return (i);
	}
	else
	{
		while(tmp)
		{
			if (tmp->content == elem->content)
				break;
			i++;
			tmp = tmp->next;
		}
		return (ft_lstsize(stack) - i);
	}
}

void	moves_indx(t_list **stack_a, t_list **stack_b)
{
	t_list *first_tmp = *stack_a;
	t_list *second_tmp = (*stack_a)->next;
	t_list *b_tmp = *stack_b;
	int i = 0;
	printf("moves table from here *********\n");
	while(b_tmp)
	{
		first_tmp = *stack_a;
		second_tmp = (*stack_a)->next;
		while(second_tmp)
		{
			if (b_tmp->content < first_tmp->content)
			{
				b_tmp->movs = 1 + best_moves(*stack_b, b_tmp);
				printf("|%d|\t", b_tmp->movs);
				break;
			}
			else if (b_tmp->content > first_tmp->content && b_tmp->content < second_tmp->content)
			{
				b_tmp->movs = 1 + best_moves(*stack_b, b_tmp) + best_moves(*stack_a, second_tmp);
				printf("|%d|\t", b_tmp->movs);
				break;
			}
			second_tmp = second_tmp->next;
			first_tmp = first_tmp->next;
		}
		i++;
		b_tmp = b_tmp->next;
	}
	printf("\nmoves table ends here *********\n");
}