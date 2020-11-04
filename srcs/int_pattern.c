/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_pattern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:22:47 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 20:14:13 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_PRECI 1
#define DEF_FIELD 0

int	output_int(t_analysed *an, int field, int precision, int target)
{
	int digit;
	int res;

	digit = ft_nbrdig(target);
	res = 0;
	if (an->is_field && !an->is_minus && (!an->is_zero || an->is_preci))
		res += output_space_preci(field, digit, precision, target);
	if (target < 0)
	{
		write(1, "-", 1);
		res++;
	}
	if (!an->is_minus && an->is_zero && !an->is_preci)
	{
		if (target < 0)
			res += output_zero(digit, field - 1);
		else
			res += output_zero(digit, field);
	}
	if (an->is_preci)
		res += output_zero(digit, precision);
	ft_putabs_fd(target, 1);
	if (an->is_minus)
		res += output_space_preci(field, digit, precision, target);
	return (res + digit);
}

int	int_pattern(t_analysed *analysed, va_list *ap)
{
	int field;
	int precision;
	int res;
	int tmp;

	field = DEF_FIELD;
	precision = DEF_PRECI;
	if (analysed->is_field)
		field = analysed->field;
	if (analysed->is_preci)
		precision = analysed->precision;
	tmp = va_arg(*ap, int);
	if (analysed->is_preci && precision == 0 && tmp == 0)
		return (output_empty(analysed));
	res = output_int(analysed, field, precision, tmp);
	return (res);
}
