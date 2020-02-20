/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:28:50 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 18:18:15 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width_c(char *s, t_data *data)
{
	char	c;

	if (*s == '*')
		data->width = va_arg(data->arg, int);
	if (*s > '0' && *s <= '9')
		data->width = ft_atoi(s);
	if (!(data->string = malloc(data->width + 1)))
		return (NULL);
	c = va_arg(data->arg, int);
	if (data->minus)
	{
		data->string[0] = c;
		filling_spaces(data->string, 1, data->width);
	}
	else
	{
		filling_spaces(data->string, 0, data->width);
		data->string[data->width - 1] = c;
	}
	return (data->string);
}

int		ft_character(char *s, t_data *data)
{
	char	c;
	char	*arg;

	if (*s == 0 || (*s == '-' && *(s + 1) == 0))
	{
		c = va_arg(data->arg, int);
		ft_putchar(c);
		return (1);
	}
	data->minus = (*s == '-') ? 1 : 0;
	if (*s == '-')
		s++;
	arg = ft_width_c(s, data);
	data->ret = ft_print(arg);
	return (data->ret);
}
