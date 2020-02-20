#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	i;

	i = 0;
	ft_printf("hello  %8.5d\n ++++ %010u\n aaaaaaa %-10X\n bbbb %c", 345, -1, 476, i);
	printf("hello %8.5d\n ++++ %010u\n aaaaaaa %-10X\n bbbb %c", 345, -1, 476, i);
	return (0);
}
