/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:19:42 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/07 15:09:24 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include <limits.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUFF_SIZE 32
# define DESC 10240
# define MAX_FD 255
# define FD_LIMIT 4986

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					my_strchri(char *s, char c);
void				my_lstadd_end(t_list **alst, t_list *new);
int					my_abs(int i);
double				my_ilerp(double val, double first, double second);
size_t				my_lstcount(t_list *lst);
int					my_splitdel(char ***split);
void				my_lstrev(t_list **alst);
int					my_count_words(const char *s, char c);
int					my_sqrt(int num);
float				my_314area(float radius);
long				my_sum(long a, long b);
float				my_fahrenheit_celsius(float fahrenheit);
float				my_celsius_fahrenheit(float celsius);
int					my_minimum(int a, int b);
int					my_maximum(int a, int b);
int					ft_toupper(int x);
int					ft_tolower(int x);
int					ft_isprint(int x);
int					ft_isalnum(int x);
int					ft_isdigit(int x);
int					ft_isalpha(int x);
int					ft_isascii(int x);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
														int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
																size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
														size_t dstsize);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *str1, const char *str2, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
															size_t len);
char				*ft_strrchr(const char *src, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);

#endif
