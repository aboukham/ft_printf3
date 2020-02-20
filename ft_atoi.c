/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:12:02 by aaboukha          #+#    #+#             */
/*   Updated: 2019/11/06 18:59:14 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	res;
	int		sign;

	sign = 1;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'
				|| *s == '\f' || *s == '\v' || *s == '\r'))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	res = 0;
	while (*s && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
		if (res * sign < -2147483648)
			return (0);
		if (res * sign > 2147483647)
			return (-1);
	}
	return (sign * res);
}