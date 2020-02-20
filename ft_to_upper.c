#include "ft_printf.h"

char	*ft_to_upper(char *s, t_data *data)
{
	data->index2 = 0;
	while (s[data->index2])
	{
		if (s[data->index2] >= 'a' && s[data->index2] <= 'z')
			s[data->index2] = s[data->index2] - 32;
		data->index2++;
	}
	return (s);
}
