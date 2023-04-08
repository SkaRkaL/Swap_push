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
void	mn_te7t_lfo9_b(t_list **stack_b, t_list *test, int a)
{
	while(1)
	{
		if((*stack_b)->content == test -> content)
			break;
		if(a == 0)
			rrb(stack_b, ft_lstsize(*stack_b));
		if(a == 1)
			rb(stack_b, ft_lstsize(*stack_b));
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
		// if (kk >= ft_lstsize(stack))
		// 	return 0;
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

int be_to_the_top(t_list *stack,t_list *elem)
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
	t_list *first_tmp;
	t_list *second_tmp;
	t_list *b_tmp = *stack_b;
	t_list *max;
	t_list *min;

	max = max_element(*stack_a);
	min = min_element(*stack_a);
	// printf("--------------<size b after moves indx %d>--------------\n", ft_lstsize(*stack_b));
	// printf("moves table from here *********\n");
	while(b_tmp)
	{
		first_tmp = *stack_a;
		second_tmp = (*stack_a)->next;
		b_tmp->place = min;
		if (b_tmp->content > max->content)
			b_tmp->movs = 1 + be_to_the_top(*stack_b, b_tmp) + be_to_the_top(*stack_a, min);
		else if (b_tmp->content < min->content)
			b_tmp->movs = 1 + be_to_the_top(*stack_b, b_tmp) + be_to_the_top(*stack_a, min);
		else 
		{
				while(second_tmp)
				{
					
					if (b_tmp->content > first_tmp->content && b_tmp->content < second_tmp->content)
					{
						b_tmp->movs = 1 + be_to_the_top(*stack_b, b_tmp) + be_to_the_top(*stack_a, second_tmp);
						b_tmp->place = second_tmp;
						break;
					}
					if (b_tmp->content < first_tmp->content && b_tmp->content > ft_lstlast(first_tmp)->content)
					{
						b_tmp->movs = 1;
						b_tmp->place = first_tmp;
						break;
					}
					second_tmp = second_tmp->next;
					first_tmp = first_tmp->next;
				}
		}
		b_tmp = b_tmp->next;
	}
	// printf("\nmoves table ends here *********\n");
}

int	stack_top_bottom(t_list *stack, t_list *best_cntnt)
{
	int	size = ft_lstsize(stack);
	int i = 0;
	while (stack->content != best_cntnt->content)
	{
		i++;
		stack = stack->next;
	}
	if (i < size / 2)
		return 1;
	return (0);
}
int	mymax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
void	push_b_to_a(t_list **stack_b, t_list **stack_a, t_list *bst_contnt)
{
	// printf("----------------> bst_contnt %d\n", bst_contnt->place->content);
	moves_indx(stack_a, stack_b);
	if (stack_top_bottom(*stack_a, bst_contnt->place) && stack_top_bottom(*stack_b, bst_contnt))
	{
		while ((*stack_a)->content != bst_contnt->place->content
			&& (*stack_b)->content != bst_contnt->content)
		{
			rr(stack_a, stack_b, 1);
		}
		while ((*stack_a)->content != bst_contnt->place->content)
			ra(stack_a, 1);
		while ((*stack_b)->content != bst_contnt->content)
			rb(stack_b, 1);
	}
	else if (!stack_top_bottom(*stack_a, bst_contnt->place) && !stack_top_bottom(*stack_b, bst_contnt))
	{
		while ((*stack_a)->content != bst_contnt->place->content
			&& (*stack_b)->content != bst_contnt->content)
		{
			rrr(stack_a, stack_b, 1);
		}
		while ((*stack_a)->content != bst_contnt->place->content)
			rra(stack_a, 1);
		while ((*stack_b)->content != bst_contnt->content)
			rrb(stack_b, 1);
	}
	else if (stack_top_bottom(*stack_a, bst_contnt->place) && !stack_top_bottom(*stack_b, bst_contnt))
	{
		while ((*stack_a)->content != bst_contnt->place->content)
			ra(stack_a, 1);
		while ((*stack_b)->content != bst_contnt->content)
			rrb(stack_b, 1);
	}
	else if (!stack_top_bottom(*stack_a, bst_contnt->place) && stack_top_bottom(*stack_b, bst_contnt))
	{
		while ((*stack_a)->content != bst_contnt->place->content)
			rra(stack_a, 1);
		while ((*stack_b)->content != bst_contnt->content)
			rb(stack_b, 1);
	}
	pa(stack_a, stack_b, ft_lstsize(*stack_a));
}