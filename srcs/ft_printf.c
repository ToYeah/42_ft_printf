/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:18:44 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/22 01:51:01 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_analysed(t_analysed *analysed)
{
	analysed->is_minus = FALSE;
	analysed->is_zero = FALSE;
	analysed->is_field = FALSE;
	analysed->field = 0;
	analysed->is_preci = FALSE;
	analysed->precision = 0;
	analysed->specifier = EXCEPTION;
	analysed->start = NULL;
	analysed->end = NULL;
}

void	set_funcs(int (**funcs)(t_analysed *, va_list *))
{
	funcs[0] = exception_pattern;
	funcs[1] = char_pattern;
	funcs[2] = string_pattern;
	funcs[3] = pointer_pattern;
	funcs[4] = int_pattern;
	funcs[5] = u_int_pattern;
	funcs[6] = lower_hex_pattern;
	funcs[7] = upper_hex_pattern;
	funcs[8] = null_char_pattern;
	funcs[9] = percent_pattern;
}

int		output_normal_char(const char *format)
{
	write(1, format, 1);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_analysed	analysed;
	int			res;
	int			(*outputs[10])(t_analysed *, va_list *);

	res = 0;
	va_start(ap, format);
	set_funcs(outputs);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			reset_analysed(&analysed);
			if (!(format = analyze_format(format, &ap, &analysed)))
				return (-1);
			res += (outputs[(int)(analysed.specifier)])(&analysed, &ap);
		}
		else
			res += output_normal_char(format);
		if (*format)
			format++;
	}
	va_end(ap);
	return (res);
}
