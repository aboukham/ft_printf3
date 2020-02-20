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

char		*ft_itoa(int n)
{
	char			*str;
	int				digit;
	int				sign;
	unsigned int	nb;

	sign = ((n < 0) ? 1 : 0);
	digit = ft_nb_digit((unsigned int)n) + sign;
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	if (n < 0)
	{
		nb = -1 * n;
		str[0] = '-';
	}
	else
		nb = n;
	str[digit] = 0;
	while (--digit >= sign)
	{
		str[digit] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
