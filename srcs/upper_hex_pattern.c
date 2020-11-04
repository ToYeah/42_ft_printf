/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_hex_pattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:03:07 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 17:47:21 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_PRECI 1
#define DEF_FIELD 0

int	output_upper_hex(t_analysed *an, int fi, int pr, unsigned int target)
{
	int digit;
	int res;

	digit = ft_nbrdig_hex(target);
	res = 0;
	if (an->is_field && !an->is_minus
	&& (!an->is_zero || an->is_preci))
		res += output_space_preci_u(fi, digit, pr);
	if (!an->is_minus && an->is_zero
	&& !an->is_preci)
		res += output_zero(digit, fi);
	if (an->is_preci)
		res += output_zero(digit, pr);
	ft_puthex_fd(target, FALSE, 1);
	if (an->is_minus)
		res += output_space_preci_u(fi, digit, pr);
	return (res + digit);
}

int	upper_hex_pattern(t_analysed *analysed, va_list *ap)
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
	res = output_upper_hex(analysed, field, precision, tmp);
	return (res);
}
