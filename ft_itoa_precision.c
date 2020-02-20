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

static void	fill_str(char *str, int nb, int sign, t_data *data)
{
	while (--data->max >= sign)
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

char		*ft_itoa_precision(int n, t_data *data)
{
	char			*str;
	int				digit;
	int				sign;
	unsigned int	nb;

	sign = ((n < 0) ? 1 : 0);
	digit =ft_nb_digit((unsigned int)n) + sign;
	data->max = (digit < data->precision) ? data->precision + sign : digit + sign;
	if (!(str = (char *)malloc(sizeof(char) * (data->max + 1))))
		return (NULL);
	if (n < 0)
	{
		nb = -1 * n;
		str[0] = '-';
	}
	else
		nb = n;
	str[data->max] = 0;
	fill_str(str, nb, sign, data);
	return (str);
}
