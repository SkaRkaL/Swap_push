/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:25 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/19 06:52:22 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "get_next_line.h"
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

//--------------------- BONUSS ------------------------
long	ft_atoi(const char *str);
char	**_parcer(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(char *c);
void	indx_stack(t_list **stack);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
int		__main_help(char ***c, t_list **stack_a, int *i);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_beforelast(t_list *lst);
char	**ft_split(char *str, char c);
char	*ft_strjoin(int size, char **strs, char *sep);

void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

void	rb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b, int indx_b);
void	pb(t_list **stack_b, t_list **stack_a, int indx_a);

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s);
t_list	*ft_lstnew(int content);
char	*ft_substr(char *s, int start, int len);
void	*check_isfree(char **str);

//-----------------------------------------------------

#endif
