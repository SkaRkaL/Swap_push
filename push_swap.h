/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:25 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/29 17:36:28 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <ctype.h>

typedef struct s_list
{
	struct s_list	*place;
	int				indx;
	int				content;
	int				flag;
	int				movs;
	int				min_move;
	struct s_list	*next;
}					t_list;

typedef struct s_elm
{
	t_list	*first_tmp;
	t_list	*second_tmp;
	t_list	*b_tmp;
}			t_elm;

long	ft_atoi(const char *str);

//----------------------------------------------
int		ft_while(t_list *stack, int size, int count);
void	inddexing_flag(t_list **stack, t_list *ret, int full_size);
t_list	*__return_help(int size, t_list **stack);
void	it_is_two_up(t_list **stack_a, t_list **stack_b, t_list *bst_contnt);
void	it_is_two_dwn(t_list **stack_a, t_list **stack_b, t_list *bst_contnt);
void	it_is_up_dwn(t_list **stack_a, t_list **stack_b, t_list *bst_contnt);
void	it_is_dwn_up(t_list **stack_a, t_list **stack_b, t_list *bst_contnt);
void	min_1(t_list **stack_a, int min);
void	min_2(t_list **stack_a, int min);
void	min_3(t_list **stack_a, int min);
void	move_while(t_list **stack_a, t_list **stack_b, t_elm *elm);
int		up_or_down(int indx_a, int indx_b, t_list *stack_a, t_list *stack_b);
char	**_parcer(int ac, char **av);
void	*check_isfree(char **str);
int		__main_help(char ***c, t_list **stack_a, int *i);
void	sort_big(t_list **stack_a, t_list **stack_b, int size);
void	__find_lis_head(t_list **stack, int full_size);
t_list	*get_best_move(t_list *stack_b);
void	is_sorted(t_list *stack_a);
int		ft_strcmp(char *s1, char *s2);
//----------------------------------------------

int		mymax(int a, int b);

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_beforelast(t_list *lst);
void	ft_lstclear(t_list **lst);

int		ft_length(char **str, char *sep, int size);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);

int		ft_isdigit(char *c);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	**ft_split(char *str, char c);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

void	sa(t_list **stack, int index);
void	sb(t_list **stack, int index);
void	ss(t_list **stack_a, t_list **stack_b, int index);

void	rb(t_list **stack_b, int index);
void	ra(t_list **stack_a, int index);
void	rr(t_list **stack_a, t_list **stack_b, int index);

void	rra(t_list **stack_a, int index);
void	rrb(t_list **stack_b, int index);
void	rrr(t_list **stack_a, t_list **stack_b, int index);

void	pa(t_list **stack_a, t_list **stack_b, int indx_b);
void	pb(t_list **stack_b, t_list **stack_a, int indx_a);

void	sort_3(t_list **stack_a);
char	*ft_itoa(int nbr);
int		max_min_element(t_list *stack, int *ret_min);

void	indx_stack(t_list **stack);
void	fun1(t_list **stack_a, t_list **stack_b, t_list *test, int a);
int		fun(t_list *stack, t_list *elem);
void	push_flag0_b(t_list **stack_a, t_list **stack_b);
void	nrml_sort(t_list **stack_a, t_list *test, int a);
void	moves_indx(t_list **stack_a, t_list **stack_b);
void	push_b_to_a(t_list **stack_b, t_list **stack_a, t_list *bst_contnt);
t_list	*max_element(t_list *stack);
t_list	*min_elmt(t_list *a);
int		help(char **c);

#endif
