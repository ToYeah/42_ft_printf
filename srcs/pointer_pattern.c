/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_pattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:29:54 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 17:13:38 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_PRECI 1
#define DEF_FIELD 0

int	output_empty_p(t_analysed *analysed)
{
	int res;

	res = 2;
	if (analysed->is_field && !analysed->is_minus)
		res += output_space(analysed->field - 2, 0);
	write(1, "0x", 2);
	if (analysed->is_field && analysed->is_minus)
		res += output_space(analysed->field - 2, 0);
	return (res);
}

int	output_pointer(t_analysed *an, int field, int preci, unsigned long target)
{
	int digit;
	int res;

	digit = ft_nbrdig_hex_ul(target);
	field -= 2;
	res = 2;
	if (an->is_field && !an->is_minus
	&& (!an->is_zero || an->is_preci))
		res += output_space_preci_u(field, digit, preci);
	write(1, "0x", 2);
	if (!an->is_minus && an->is_zero
	&& !an->is_preci)
		res += output_zero(digit, field);
	if (an->is_preci)
		res += output_zero(digit, preci);
	if (!(an->is_preci && preci == 0 && !target))
		ft_puthex_ul_fd(target, TRUE, 1);
	if (an->is_minus)
		res += output_space_preci_u(field, digit, preci);
	return (res + digit);
}

int	pointer_pattern(t_analysed *analysed, va_list *ap)
{
	int				field;
	int				precision;
	int				res;
	unsigned long	tmp;

	field = DEF_FIELD;
	precision = DEF_PRECI;
	if (analysed->is_field)
		field = analysed->field;
	if (analysed->is_preci)
		precision = analysed->precision;
	tmp = (unsigned long)va_arg(*ap, void *);
	if (analysed->is_preci && precision == 0 && tmp == 0)
		return (output_empty_p(analysed));
	res = output_pointer(analysed, field, precision, tmp);
	return (res);
}
