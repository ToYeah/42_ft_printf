/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 19:51:59 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 20:14:18 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_FIELD 0

int	output_char(t_analysed *an, int field, unsigned char target)
{
	int res;

	res = 0;
	if (field > 1 && !an->is_minus)
	{
		if (an->is_zero)
			res += output_zero(1, field);
		else
			res += output_space(field, 1);
	}
	write(1, &target, 1);
	res++;
	if (field > 1 && an->is_minus)
		res += output_space(field, 1);
	return (res);
}

int	char_pattern(t_analysed *analysed, va_list *ap)
{
	int field;
	int res;

	field = DEF_FIELD;
	if (analysed->is_field)
		field = analysed->field;
	res = output_char(analysed, field, (unsigned char)(va_arg(*ap, int)));
	return (res);
}
