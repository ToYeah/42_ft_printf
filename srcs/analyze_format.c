/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:03:01 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/22 00:51:09 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*set_preci(const char *str, va_list *ap, int *preci, t_bool *flag)
{
	if (*str == '*')
	{
		*preci = va_arg(*ap, int);
		str++;
	}
	else
	{
		if (!ft_atoi_limit(str, preci))
			return (NULL);
		while (ft_isdigit(*str))
			str++;
	}
	if (*preci < 0)
		*flag = FALSE;
	else
		*flag = TRUE;
	return (str);
}

const char	*set_field(const char *str, va_list *ap, t_analysed *analysed)
{
	if (*str == '*')
	{
		analysed->field = va_arg(*ap, int);
		str++;
	}
	else
	{
		if (!ft_atoi_limit(str, &(analysed->field)))
			return (NULL);
		if (*str == '-')
			str++;
		while (ft_isdigit(*str))
			str++;
	}
	analysed->is_field = TRUE;
	if (analysed->field < 0)
	{
		analysed->field *= -1;
		analysed->is_minus = TRUE;
	}
	return (str);
}

t_specifier	get_specifier(const char *str)
{
	if (*str == 'c')
		return (CHAR);
	else if (*str == 's')
		return (STRING);
	else if (*str == 'p')
		return (POINTER);
	else if (*str == 'd' || *str == 'i')
		return (INT);
	else if (*str == 'u')
		return (UNSIGNED_INT);
	else if (*str == 'x')
		return (LOWER_HEX);
	else if (*str == 'X')
		return (UPPER_HEX);
	else if (*str == '\0')
		return (NULL_CHAR);
	else if (*str == '%')
		return (PERCENT);
	else
		return (EXCEPTION);
}

const char	*analyze_format(const char *str, va_list *ap, t_analysed *format)
{
	format->start = str;
	str++;
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			format->is_minus = TRUE;
		else if (*str == '0')
			format->is_zero = TRUE;
		str++;
	}
	if (*str == '*' || ft_isdigit(*str))
		if (!(str = set_field(str, ap, format)))
			return (NULL);
	if (*str == '.')
	{
		str++;
		if (!(str = set_preci(str, ap, &(format->precision),
		&(format->is_preci))))
			return (NULL);
	}
	format->specifier = get_specifier(str);
	format->end = str;
	return (str);
}
