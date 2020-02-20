/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:21:27 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/31 18:26:44 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_digit(unsigned int n)
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

static void	fill_str(char *str, unsigned int nb, t_data *data)
{
	while (--data->max >= 0)
	{
		if (nb == '0')
			str[data->max] = '0';
		else
		{
			str[data->max] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
}

char		*ft_uitoa_precision(unsigned int n, t_data *data)
{
	char			*str;
	int				digit;

	digit = nb_digit(n);
	data->max = (digit < data->precision) ? data->precision : digit;
	if (!(str = (char *)malloc(sizeof(char) * (data->max + 1))))
		return (NULL);
	str[data->max] = 0;
	fill_str(str, n, data);
	return (str);
}
