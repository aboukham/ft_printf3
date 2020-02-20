#include "ft_printf.h"

static char	*flag_zero(char *arg, t_data *data)
{
	int		sign;

	sign = (arg[0] == '-') ? 1 : 0;
	if (data->string[0] == '-')
		data->string[data->index1] = '0';
	while (--data->index1 >= sign)
		data->string[data->index1] = '0';
	if (arg[0] == '-')
		data->string[0] = '-';
	return (data->string);
}

char	*flag_minus(char *arg, t_data *data)
{
	if (data->minus == 1)
	{
		data->index1 = -1;
		while (++data->index1 < data->len)
			data->string[data->index1] = arg[data->index1];
		if (data->width < data->len)
			data->string[data->index1] = 0;
	}
	else
	{
		data->index2 = data->len;
		data->index1 = ft_strlen(data->string) - 1;
		while (--data->index2 >= 0)
		{
			if (arg[data->index2] != '-')
				data->string[data->index1] = arg[data->index2];
			else
				data->string[0] = '-';
			data->index1--;
		}
		data->index1++;
		if (data->specif != 's' && data->specif != 'c'&& data->specif != 'p')
			if (!data->dot && data->zero)
				data->string = flag_zero(arg, data);
	}
	free(arg);
	return (data->string);
}
