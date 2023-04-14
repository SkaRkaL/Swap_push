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

int	up_or_down_moves(int indx_a, int indx_b, t_list *stack_a , t_list *stack_b)
{
	int	two_up;
	int	two_dwn;
	int	up_dwn;
	int	dwn_up;

	two_up = mymax(indx_a, indx_b);
	two_dwn = mymax(ft_lstsize(stack_a) - indx_a, ft_lstsize(stack_b) - indx_b);
	up_dwn = indx_a + ft_lstsize(stack_b) - indx_b;
	dwn_up = indx_b + ft_lstsize(stack_a) - indx_a;

	if (two_up <= two_dwn && two_up <= up_dwn && two_up <= dwn_up)
		return (two_up);
	if (two_dwn <= two_up && two_dwn <= up_dwn && two_dwn <= dwn_up)
		return (two_dwn);
	if (up_dwn <= two_up && up_dwn <= two_dwn && up_dwn <= dwn_up)
		return (up_dwn);
	if (dwn_up <= two_up && dwn_up <= two_dwn && dwn_up <= up_dwn)
		return (dwn_up);
	else
		return (0);
}

int	up_or_down_type(int indx_a, int indx_b, t_list *stack_a , t_list *stack_b)
{
	int	two_up;
	int	two_dwn;
	int	up_dwn;
	int	dwn_up;

	two_up = mymax(indx_a, indx_b);
	two_dwn = mymax(ft_lstsize(stack_a) - indx_a, ft_lstsize(stack_b) - indx_b);
	up_dwn = indx_a + ft_lstsize(stack_b) - indx_b;
	dwn_up = indx_b + ft_lstsize(stack_a) - indx_a;

	if (two_up <= two_dwn && two_up <= up_dwn && two_up <= dwn_up)
		return (1);
	if (two_dwn <= two_up && two_dwn <= up_dwn && two_dwn <= dwn_up)
		return (2);
	if (up_dwn <= two_up && up_dwn <= two_dwn && up_dwn <= dwn_up)
		return (3);
	if (dwn_up <= two_up && dwn_up <= two_dwn && dwn_up <= up_dwn)
		return (4);
	else
		return (0);
}

void	moves_indx(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_tmp;
	t_list	*second_tmp;
	t_list	*b_tmp = *stack_b;
	t_list	*max;
	t_list	*min;

	max = max_element(*stack_a);
	min = min_element(*stack_a);
	while(b_tmp)
	{
		first_tmp = *stack_a;
		second_tmp = (*stack_a)->next;
		b_tmp->place = min;
		if (b_tmp->content > max->content || b_tmp->content < min->content)
			b_tmp->movs = 1 + up_or_down_moves(min->indx, b_tmp->indx, *stack_a, *stack_b);
		else
		{
			while(second_tmp)
			{
				
				if (b_tmp->content > first_tmp->content && b_tmp->content < second_tmp->content)
				{
					b_tmp->movs = 1 + up_or_down_moves(second_tmp->indx, b_tmp->indx, *stack_a, *stack_b);
					b_tmp->place = second_tmp;
					break;
				}
				if (b_tmp->content < first_tmp->content && b_tmp->content > ft_lstlast(first_tmp)->content)
				{
					b_tmp->movs = 1 + up_or_down_moves(first_tmp->indx, b_tmp->indx, *stack_a, *stack_b);
					b_tmp->place = first_tmp;
					break;
				}
				second_tmp = second_tmp->next;
				first_tmp = first_tmp->next;
			}
		}
		b_tmp = b_tmp->next;
	}
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
	if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 1)
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
	else if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 2)
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
	else if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 3)
	{
		while ((*stack_a)->content != bst_contnt->place->content)
			ra(stack_a, 1);
		while ((*stack_b)->content != bst_contnt->content)
			rrb(stack_b, 1);
	}
	else if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 4)
	{
		while ((*stack_a)->content != bst_contnt->place->content)
			rra(stack_a, 1);
		while ((*stack_b)->content != bst_contnt->content)
			rb(stack_b, 1);
	}
	pa(stack_a, stack_b, ft_lstsize(*stack_a));
}