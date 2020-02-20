/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:21:16 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 22:53:19 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char *t = "cspdiuxX";

static int		check_specif(char *s, t_data *data)
{
	if (data->specif == 'd' || data->specif == 'i')
		data->ret = data->ret + ft_integer(s, data);
	if (data->specif == 'u')
		data->ret = data->ret + ft_u(s, data);
	if (data->specif == 's')
		data->ret = data->ret + ft_string(s, data);
	if (data->specif == 'c')
		data->ret = data->ret + ft_character(s, data);
	if (data->specif == 'x' || data->specif == 'X')
		data->ret = data->ret + ft_xX(s, data);
	if (data->specif == 'p')
		data->ret = data->ret + ft_p(s, data);
	return (data->ret);
}

static void		get_arg(char *s, t_data *data)
{
	int		j;
	char	*str;
	
	data->index3 = 0;
	while (s[data->index3])
	{
		j = 0;
		while (t[j] && t[j] != s[data->index3])
			j++;
		if (t[j] == s[data->index3])
		{
			data->specif = t[j];
			str = ft_substr((const char *)s, 0, (size_t)data->index3);
			check_specif(str, data);
			free(str);
			break ;
		}
		data->index3++;
	}	
}

static void		ft_strparsing(char *s, t_data *data)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s == '%')
		{
			get_arg(s + 1, data);
			s = s + data->index3 + 1;
			j = j + data->index3 + 1;
		}
		else
		{
			ft_putchar(*s);
			data->ret = data->ret + 1;
		}
		s++;
		j++;
	}
}

int		ft_printf(const char *s, ...)
{
	t_data	data;

	data.ret = 0;
	//data.format_str = (char *)s;
	va_start(data.arg, s);
	ft_strparsing((char *)s, &data);
	va_end(data.arg);
	return (data.ret);
}
