/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 09:48:11 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:36:00 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define CHAR				'\0'
# define UNSIGNED_CHAR		'\1'
# define SHORT				'\2'
# define UNSIGNED_SHORT		'\3'
# define LONG				'\4'
# define UNSIGNED_LONG		'\5'
# define LONG_LONG			'\6'
# define UNSIGNED_LONG_LONG	'\7'
# define INTEGER			'\10'
# define UNSIGNED_INTEGER	'\11'

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	char				T;

typedef struct				s_format
{
	int						hash;
	int						plus;
	int						minus;
	int						hh;
	int						h;
	int						l;
	int						ll;
	int						L;
	int						precision;
	int						width;
	int						zero;
}							t_format;

void						add_flags(char *str, t_format *format);
void						add_zero(char *str, t_format *format);
void						add_precision(char *str, t_format *format);
void						add_width(char *str, t_format *format);
int							ft_printf(const char *format, ...);
t_format					*get_format(char *str, int j);
char						*get_num_str(int *i, unsigned long long n, int b, int c);
void						ft_putchar_wc(char c, int *chars);
void						ft_putstr_wc(char *str, int *chars);
void						print_with_flags(char *s, t_format *f, int *a, char c);
int							print_float(unsigned long long g, long double n, t_format *f, int is);
int							put_float(va_list l, t_format *f, int *c);
void						put_num(va_list l, t_format *f, int *a, char c);
void						put_pointer(va_list l, int *c);
void						put_string(va_list l, t_format *f, int *c);
T							hh(char c);
T							h(char c);
T							l(char c);
T							ll(char c);
T							no_flag(char c);
unsigned long long			c_arg(va_list list, int *is_negative);
unsigned long long			s_arg(va_list list, int *is_negative);
unsigned long long			l_arg(va_list list, int *is_negative);
unsigned long long			ll_arg(va_list list, int *is_negative);
unsigned long long			i_arg(va_list list, int *is_negative);

#endif
