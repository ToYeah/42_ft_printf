/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:19:26 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/22 01:43:32 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEF_FIELD 0
#define DEF_PRECI 1

int	null_char_pattern(t_analysed *analysed, va_list *ap)
{
	(void)analysed;
	(void)ap;
	write(1, "\0", 1);
	return (0);
}

int	percent_pattern(t_analysed *analysed, va_list *ap)
{
	int field;
	int res;

	(void)ap;
	res = 0;
	field = DEF_FIELD;
	if (analysed->is_field)
		field = analysed->field;
	if (analysed->is_field && !analysed->is_minus && !analysed->is_zero)
		res += output_space(field, 1);
	if (!analysed->is_minus && analysed->is_zero)
		res += output_zero(1, field);
	write(1, "%%", 1);
	if (analysed->is_minus)
		res += output_space(field, 1);
	return (res + 1);
}

int	exception_pattern(t_analysed *analysed, va_list *ap)
{
	int res;

	(void)ap;
	res = 0;
	while (analysed->start <= analysed->end)
	{
		write(1, analysed->start, 1);
		analysed->start++;
		res++;
	}
	return (res);
}
