#include "ft_printf.h"

int	ft_nb_digit(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n / 10)
	{
		digit++;
		n = n / 10;
	}
	return (digit);
}


