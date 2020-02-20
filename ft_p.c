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

static char	*ft_width_p(char *s, t_data *data)
{
	char	*arg;

	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	arg = ft_convert_to_exa(va_arg(data->arg, long long int), data);
	data->len = ft_strlen(arg);
	data->max = (data->len < data->width) ? data->width : data->len;
	if (!(data->string = malloc(data->max + 1)))
		return (NULL);
	filling_spaces(data->string, 0, data->max);
	data->string = flag_minus(arg, data);
	return (data->string);
}

int		ft_p(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	if (*s == 0 || (*s == '-' && *(s + 1) == 0) || (*s == '0' && *(s + 1) == 0))
		arg = ft_convert_to_exa(va_arg(data->arg, long long int), data);
	else
	{
		data->minus = (*s == '-') ? 1 : 0;
		if (*s == '-')
			s++;
		arg = ft_width_p(s, data);
	}
	data->ret = ft_print(arg);
	return (data->ret);
}
