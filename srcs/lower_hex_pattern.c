/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_hex_pattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:36:13 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 20:14:16 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_PRECI 1
#define DEF_FIELD 0

int	output_lower_hex(t_analysed *an, int field, int preci, unsigned int target)
{
	int digit;
	int res;

	digit = ft_nbrdig_hex(target);
	res = 0;
	if (an->is_field && !an->is_minus
	&& (!an->is_zero || an->is_preci))
		res += output_space_preci_u(field, digit, preci);
	if (!an->is_minus && an->is_zero
	&& !an->is_preci)
		res += output_zero(digit, field);
	if (an->is_preci)
		res += output_zero(digit, preci);
	ft_puthex_fd(target, TRUE, 1);
	if (an->is_minus)
		res += output_space_preci_u(field, digit, preci);
	return (res + digit);
}

int	lower_hex_pattern(t_analysed *analysed, va_list *ap)
{
	int				field;
	int				precision;
	int				res;
	unsigned int	tmp;

	field = DEF_FIELD;
	precision = DEF_PRECI;
	if (analysed->is_field)
		field = analysed->field;
	if (analysed->is_preci)
		precision = analysed->precision;
	tmp = va_arg(*ap, unsigned int);
	if (analysed->is_preci && precision == 0 && tmp == 0)
		return (output_empty(analysed));
	res = output_lower_hex(analysed, field, precision, tmp);
	return (res);
}
