#include "push_swap.h"

void	move_while(t_list **stack_a, t_list **stack_b, t_elm *elm)
{
	while(elm->second_tmp)
	{
		if (elm->b_tmp->content > elm->first_tmp->content && elm->b_tmp->content < elm->second_tmp->content)
		{
			elm->b_tmp->movs = 1 + up_or_down_moves(elm->second_tmp->indx, elm->b_tmp->indx, *stack_a, *stack_b);
			elm->b_tmp->place = elm->second_tmp;
			break;
		}
		if (elm->b_tmp->content < elm->first_tmp->content && elm->b_tmp->content > ft_lstlast(elm->first_tmp)->content)
		{
			elm->b_tmp->movs = 1 + up_or_down_moves(elm->first_tmp->indx, elm->b_tmp->indx, *stack_a, *stack_b);
			elm->b_tmp->place = elm->first_tmp;
			break;
		}
		elm->second_tmp = elm->second_tmp->next;
		elm->first_tmp = elm->first_tmp->next;
	}
}