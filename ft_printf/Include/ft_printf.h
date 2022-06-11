/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:44:16 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 01:51:31 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <stdint.h>

typedef struct str_list
{
	char	*str;
	int		form;
	char	type;
}			t_strlist;

int		ok_char(char c);
int		end_char(char c);
void	init_flags(t_strlist *lst);
int		check_f(t_strlist *lst);
char	*ft_uitoa(unsigned int n);

void	ft_clear_flst(void *lst);
char	*ft_str_toupper(char *s);
char	*ft_tohex(unsigned int nb);

int		ft_printf(const char *format, ...);
char	*ft_getaddr(void *ptr);
size_t	print_format(t_strlist *s, va_list *arg);
size_t	print_lst(void *data, va_list *arg);

size_t	ft_lstiter_printf(t_list *lst, va_list *va_lst,
			size_t (*f)(void *, va_list *));
#endif