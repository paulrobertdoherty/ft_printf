/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 09:48:11 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/19 20:27:48 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf_types.h"
# include "libft/libft.h"

void				add_flags(char *str, t_format *format);
void				add_zero(char *str, t_format *format);
void				add_precision(char *str, t_format *format);
void				add_width(char *str, t_format *format);
int					ft_printf(const char *format, ...);
t_format			*get_format(char *str, int j);
char				*get_num_str(int *i, unsigned long long n, char c, t_format *f);
void				ft_putchar_wc(char c, int *chars);
void				ft_putstr_wc(char *str, int *chars);
void				print_with_flags(char *s, t_format *f, int *a);
void				printc_with_flags(char c, t_format *f, int *a);
int					print_float(ull g, long double n, t_format *f, int is);
int					put_float(va_list l, t_format *f, int *c);
void				put_num(va_list l, t_format *f, int *a, char c);
void				put_pointer(va_list l, int *c);
void				put_string(va_list l, t_format *f, int *c);
T					hh(char c);
T					h(char c);
T					l(char c);
T					ll(char c);
T					no_flag(char c);
unsigned long long	c_arg(va_list list, int *is_negative);
unsigned long long	s_arg(va_list list, int *is_negative);
unsigned long long	l_arg(va_list list, int *is_negative);
unsigned long long	ll_arg(va_list list, int *is_negative);
unsigned long long	i_arg(va_list list, int *is_negative);
char				*get_front(char *str, ull n, char c, t_format *format);

#endif
