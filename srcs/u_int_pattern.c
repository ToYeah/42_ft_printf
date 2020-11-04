/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:29:53 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 17:59:12 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_PRECI 1
#define DEF_FIELD 0

int	output_u_int(t_analysed *an, int field, int preci, unsigned int target)
{
	int digit;
	int res;

	digit = ft_nbrdig_ui(target);
	res = 0;
	if (an->is_field && !an->is_minus && (!an->is_zero || an->is_preci))
		res += output_space_preci_u(field, digit, preci);
	if (!an->is_minus && an->is_zero && !an->is_preci)
		res += output_zero(digit, field);
	if (an->is_preci)
		res += output_zero(digit, preci);
	ft_putnbr_ui_fd(target, 1);
	if (an->is_minus)
		res += output_space_preci_u(field, digit, preci);
	return (res + digit);
}

int	u_int_pattern(t_analysed *analysed, va_list *ap)
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
	res = output_u_int(analysed, field, precision, tmp);
	return (res);
}
