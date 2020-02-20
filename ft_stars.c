/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:14:49 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/31 17:14:57 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_stars(char *s, t_data *data)
{
	if ( *s == '*' && data->dot && *(data->dot + 1) == '*')
	{
		data->width = va_arg(data->arg, int);
		data->precision = va_arg(data->arg, int);
		return (3);
	}
	else if (*s == '*')
	{
		data->width = va_arg(data->arg, int);
		return (1);
	}
	else if (data->dot && *(data->dot + 1) == '*')
	{
		data->precision = va_arg(data->arg, int);
		return (2);
	}
	return (0);
}
