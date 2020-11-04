/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:09:43 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/21 17:45:56 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_space(int field, int to_subtract)
{
	int i;
	int limit;

	i = 0;
	limit = field - to_subtract;
	while (i < limit)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	output_space_preci(int field, int digit, int precision, int target)
{
	int i;
	int max;
	int limit;

	max = digit;
	if (digit < precision)
		max = precision;
	if (target < 0)
		max++;
	i = 0;
	limit = field - max;
	while (i < limit)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	output_space_preci_u(int field, int digit, int precision)
{
	int i;
	int max;
	int limit;

	max = digit;
	if (digit < precision)
		max = precision;
	i = 0;
	limit = field - max;
	while (i < limit)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	output_zero(int digit, int precision)
{
	int i;

	i = 0;
	while (i < precision - digit)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	output_empty(t_analysed *analysed)
{
	if (analysed->is_field)
		return (output_space(analysed->field, 0));
	return (0);
}
