#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef struct	s_list
{
	int content;
	struct s_list *next;
} t_list;

int	ft_atoi(const char *str);

t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_beforelast(t_list *lst);


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



void	sort_III(t_list **stack_a);
void	sort_V(t_list **stack_a, t_list **stack_b);
int		max_min_element(t_list *stack, int *ret_min);



#endif
