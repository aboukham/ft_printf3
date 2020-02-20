#include "ft_printf.h"
#include <stdio.h>

char	s[] = "0123456789abcdef";

int		ft_size(long long int x)
{
	int		i;

	i = 1;
	while (x / 16)
	{
		i++;
		x = x / 16;
	}
	return (i);
}

char	*ft_convert_to_exa(long long int x, t_data *data)
{
	char	*str;
	int		size;

	size = ft_size(x);
	if (data->specif == 'p')
		size = size + 2;
	if (!(str = malloc(size + 1)))
		return (NULL);
	data->index1 = size;
	str[data->index1--] = 0;
	if (x == 0)
		str[data->index1] = '0';
	while (x)
	{
		str[data->index1] = s[x % 16];
		x = x / 16;
		data->index1--;
	}
	if (data->specif == 'p')
	{
		str[data->index1--] = 'x';
		str[data->index1] = '0';
	}
	return (str);
}
