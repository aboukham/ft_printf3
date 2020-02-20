/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:43:46 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/31 18:24:20 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	nb_digit(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n / 10)
	{
		digit++;
		n = n / 10;
	}
	return (digit);
}

char		*ft_uitoa(unsigned int n)
{
	char			*str;
	int				digit;

	digit = nb_digit(n);
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = 0;
	while (--digit >= 0)
	{
		str[digit] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
