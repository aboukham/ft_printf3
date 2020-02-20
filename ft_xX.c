/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:04 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/31 17:35:33 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width_x(char *s, t_data *data, char *arg)
{
	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	if (arg == NULL)
		arg = ft_convert_to_exa((long long int)va_arg(data->arg, unsigned int), data);
	data->len = ft_strlen(arg);
	data->max = (data->len < data->width) ? data->width : data->len;
	if (!(data->string = malloc(data->max + 1)))
		return (NULL);
	filling_spaces(data->string, 0, data->max);
	data->string = flag_minus(arg, data);
	return (data->string);
}

static char	*ft_precision_x(char *s, t_data *data, char *arg)
{
	if (*s == 0)
		data->precision = 0;
	else if (data->star == 0 || data->star == 1)
			data->precision = ft_atoi(s);
	arg = ft_convert_to_exa((long long int)va_arg(data->arg, unsigned int), data);
	return (arg);
}

int		ft_xX(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	arg = NULL;
	data->dot = ft_strchr(s, '.');
	if (data->specif == 'x' || data->specif == 'X')
		if (*s == 0 || (*s == '-' && *(s + 1) == 0) || (*s == '0' && *(s + 1) == 0))
			arg = ft_convert_to_exa((long long int)va_arg(data->arg, unsigned int), data);
	data->minus = (*s == '-') ? 1 : 0;
	data->zero = (*s == '0') ? 1: 0;
	if (*s == '-' || *s == '0')
		s++;
	data->star = ft_stars(s, data);
	if (data->dot)
		arg = ft_precision_x(data->dot + 1, data, arg);
	if ((*s > '0' && *s <= '9') || *s == '*')
		arg = ft_width_x(s, data, arg);
	if (data->specif == 'X')
		arg = ft_to_upper(arg, data);
	data->ret = ft_print(arg);
	return (data->ret);
}
