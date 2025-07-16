/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:01 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/03/27 00:43:58 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_cmd
{
	char			**cmd;
	char			*path;
	int				pos;
	struct s_cmd	*next;
}	t_cmd;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_atoi_base(char *str, char *base);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			**ft_splitcmd(char const *s, char c, char *cmd, int i);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strichr(char *str, char to_find);
t_cmd			*ft_lstnew(char **content, int i);
t_cmd			*ft_lstlast(t_cmd *lst);
void			ft_lstadd_front(t_cmd **alst, t_cmd *new);
int				ft_lstsize(t_cmd *lst);
void			ft_lstadd_back(t_cmd **alst, t_cmd *new);
void			ft_lstdelone(t_cmd *lst, void (*del)(char**));
void			ft_lstclear(t_cmd **lst, void (*del)(char**));
void			ft_lstiter(t_cmd *lst, void (*f)(void *));
t_cmd			*ft_lstmap(t_cmd *lst, void *(*f)(void *),
					void (*del)(void *));
char			*ft_strdupp(char const *s, char c, int *i);
int				ft_check_c(char c, char s);
int				ft_count_c(char c, const char *s);

#endif
