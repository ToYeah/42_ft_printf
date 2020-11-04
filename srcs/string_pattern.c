/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:29:50 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 17:49:26 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_PRECI 0
#define DEF_FIELD 0
#define NULL_STR "(null)"

int	output_string(t_analysed *an, int field, int preci, const char *target)
{
	int res;
	int len;

	res = 0;
	if (target)
		len = ft_strlen(target);
	else
		len = ft_strlen(NULL_STR);
	if (an->is_preci)
		len = ft_get_lower(len, preci);
	if (an->is_field && field > len && !an->is_minus && an->is_zero)
		res += output_zero(len, field);
	else if (an->is_field && field > len && !an->is_minus)
		res += output_space(field, len);
	if (target && an->is_preci)
		ft_putstr_limit((char *)target, ft_get_lower(len, preci));
	else if (target)
		ft_putstr_limit((char *)target, len);
	else if (!target && an->is_preci)
		ft_putstr_limit(NULL_STR, ft_get_lower(len, preci));
	else
		ft_putstr_limit(NULL_STR, ft_strlen(NULL_STR));
	if (an->is_field && field > len && an->is_minus)
		res += output_space(field, len);
	return (res + len);
}

int	string_pattern(t_analysed *analysed, va_list *ap)
{
	int			field;
	int			precision;
	int			res;
	const char	*tmp;

	field = DEF_FIELD;
	precision = DEF_PRECI;
	if (analysed->is_preci && analysed->precision < 0)
		analysed->is_preci = FALSE;
	if (analysed->is_field)
		field = analysed->field;
	if (analysed->is_preci)
		precision = analysed->precision;
	tmp = va_arg(*ap, const char *);
	res = output_string(analysed, field, precision, tmp);
	return (res);
}
