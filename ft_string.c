/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:34:53 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 13:25:37 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision_s(char *s, t_data *data)
{
	char	*arg;

	if (*s == 0)
		data->precision = 0;
	else if (data->star == 0 || data->star == 1)
			data->precision = ft_atoi(s);
	data->string = va_arg(data->arg, char *);
	data->len = ft_strlen(data->string);
	data->min = (data->precision < data->len) ? data->precision : data->len;
	if (!(arg = malloc(data->min + 1)))
		return (NULL);
	data->index1 = -1;
	while (++data->index1 < data->min)
		arg[data->index1] = data->string[data->index1];
	arg[data->index1] = 0;
	return (arg);
}

static char	*ft_width_s(char *s, t_data *data, char *arg)
{
	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	if (arg == NULL)
		arg = va_arg(data->arg, char *);
	data->len = ft_strlen(arg);
	data->max = (data->len < data->width) ? data->width : data->len;
	if (!(data->string = malloc(data->max + 1)))
		return (NULL);
	filling_spaces(data->string, 0, data->max);
	data->string = flag_minus(arg, data);
	return (data->string);
}

int		ft_string(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	arg = NULL;
	data->dot = ft_strchr(s, '.');
	if (*s == 0 || (*s == '-' && *(s + 1) == 0))
		arg = va_arg(data->arg, char *);
	data->minus = (*s == '-') ? 1 : 0;
	if (*s == '-')
		s++;
	data->star = ft_stars(s, data);
	if (data->dot)
		arg = ft_precision_s(data->dot + 1, data);
	if ((*s > '0' && *s <= '9') || *s == '*')
		arg = ft_width_s(s, data, arg);
	data->ret = ft_print(arg);
	return (data->ret);
}
