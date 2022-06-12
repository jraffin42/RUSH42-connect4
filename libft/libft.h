/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:56:24 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 15:23:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/select.h>
# include <sys/types.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 4096
# endif

# ifndef GNL_FD_MAXSIZE
#  define GNL_FD_MAXSIZE FD_SETSIZE
# endif

typedef struct s_gnlbuf
{
	char	data[GNL_BUFFER_SIZE];
	ssize_t	size;
}	t_gnlbuf;

typedef struct str_list
{
	char	*str;
	int		form;
	char	type;
}			t_strlist;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ok_char(char c);
int		end_char(char c);
int		check_f(t_strlist *lst);
int		ft_printf(const char *format, ...);

void	init_flags(t_strlist *lst);
void	ft_clear_flst(void *lst);

char	*ft_printf_itoa(int n);
char	*ft_getaddr(void *ptr);
char	*ft_str_toupper(char *s);
char	*ft_uitoa(unsigned int n);
char	*ft_tohex(unsigned int nb);

size_t	print_format(t_strlist *s, va_list *arg);
size_t	print_lst(void *data, va_list *arg);
size_t	ft_lstiter_printf(t_list *lst, va_list *va_lst, \
		size_t (*f)(void *, va_list *));

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	**ft_free_tab(char **spt);
size_t	ft_strlen(const char *s);
size_t	ft_countw(const char *str, char c);
size_t	ft_lenw(const char *str, char c);
size_t	ft_strnlen(const char *s, size_t maxlen);
size_t	ft_wcslen(const wchar_t *s);
size_t	ft_wcsnlen(const wchar_t *s, size_t maxlen);
int		ft_isspace(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_basename(char *path);
int		ft_atoi(const char *nptr);
int		ft_atoi_err(const char *str, int *nbr);
int		ft_atoll_err(const char *str, long long int *nbr);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s0, char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n, char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int n);
int		ft_intlen(int n);

char	*ft_gnl(int fd);

int		ft_put_error(char *launch_path, char *object, char *msg, int ret_value);

#endif
