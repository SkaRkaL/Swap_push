#include "push_swap.h"

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
	int	two_dwn;
	int	two_up;
	int	dwn_up;
	int	up_dwn;

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
	t_elm 	elm;
	t_list	*max;
	t_list	*min;

	
	elm.b_tmp = *stack_b;
	max = max_element(*stack_a);
	min = min_element(*stack_a);
	while(elm.b_tmp)
	{
		elm.first_tmp = *stack_a;
		elm.second_tmp = (*stack_a)->next;
		elm.b_tmp->place = min;
		if (elm.b_tmp->content > max->content || elm.b_tmp->content < min->content)
			elm.b_tmp->movs = 1 + up_or_down_moves(min->indx, elm.b_tmp->indx, *stack_a, *stack_b);
		else
		{
			move_while(stack_a, stack_b, &elm);
		}
		elm.b_tmp = elm.b_tmp->next;
	}
}

void	push_b_to_a(t_list **stack_b, t_list **stack_a, t_list *bst_contnt)
{
	if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 1)
		it_is_two_up(stack_a, stack_b, bst_contnt);
	else if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 2)
		it_is_two_dwn(stack_a, stack_b, bst_contnt);
	else if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 3)
		it_is_up_dwn(stack_a, stack_b, bst_contnt);
	else if (up_or_down_type(bst_contnt->place->indx, bst_contnt->indx, *stack_a , *stack_b) == 4)
		it_is_dwn_up(stack_a, stack_b, bst_contnt);
	pa(stack_a, stack_b, ft_lstsize(*stack_a));
}