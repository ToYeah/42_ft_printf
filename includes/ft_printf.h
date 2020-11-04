/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:15:47 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/22 01:52:18 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef enum	e_specifier
{
	EXCEPTION,
	CHAR,
	STRING,
	POINTER,
	INT,
	UNSIGNED_INT,
	LOWER_HEX,
	UPPER_HEX,
	NULL_CHAR,
	PERCENT
}				t_specifier;

typedef struct	s_analysed
{
	t_bool		is_minus;
	t_bool		is_zero;
	t_bool		is_field;
	int			field;
	t_bool		is_preci;
	int			precision;
	t_specifier	specifier;
	const char	*start;
	const char	*end;
}				t_analysed;

const char		*analyze_format(const char *str, va_list *ap, t_analysed *f);
int				ft_printf(const char *format, ...);
int				char_pattern(t_analysed *analysed, va_list *ap);
int				string_pattern(t_analysed *analysed, va_list *ap);
int				pointer_pattern(t_analysed *analysed, va_list *ap);
int				int_pattern(t_analysed *analysed, va_list *ap);
int				u_int_pattern(t_analysed *analysed, va_list *ap);
int				lower_hex_pattern(t_analysed *analysed, va_list *ap);
int				upper_hex_pattern(t_analysed *analysed, va_list *ap);
int				exception_pattern(t_analysed *analysed, va_list *ap);
int				null_char_pattern(t_analysed *analysed, va_list *ap);
int				percent_pattern(t_analysed *analysed, va_list *ap);
int				exception_pattern(t_analysed *analysed, va_list *ap);
int				output_space(int field, int to_subtract);
int				output_space_preci(int field, int digit, int pr, int target);
int				output_space_preci_u(int field, int digit, int precision);
int				output_zero(int digit, int precision);
int				output_empty(t_analysed *analysed);

#endif
