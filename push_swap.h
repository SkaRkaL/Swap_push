#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <ctype.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}				t_list;


t_list	*ft_lstnew(void *content);

int		ft_isdigit(char  *c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *s);
char	**ft_split(char *str, char c);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);


#endif
 