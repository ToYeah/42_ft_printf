/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:20:48 by totaisei          #+#    #+#             */
/*   Updated: 2020/10/10 13:46:40 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	size_t	len;

	len = 1;
	i = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * len)))
		return (NULL);
	if (s1)
		while (*s1)
			res[i++] = *s1++;
	if (s2)
		while (*s2)
			res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
