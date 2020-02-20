/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:01:01 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 17:51:58 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		minus;
	int		width;
	int		ret;
	int		star;
	int		precision;
	int		len;
	int		min;
	int		max;
	int		index1;
	int		index2;
	int		index3;
	int		zero;
	char	specif;
	char	*dot;
	char	*string;
	va_list	arg;
}				t_data;

char    *ft_substr(const char *s, unsigned int start, int len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_atoi(const char *s);
int		ft_printf(const char *s, ...);
char	*str_reverse(char *s);
int		ft_print(char *s);
void	filling_spaces(char *s, int start, int end);
int		ft_stars(char *s, t_data *data);
int		ft_string(char *s, t_data *data);
int		ft_character(char *s, t_data *data);
int		ft_integer(char *s, t_data *data);
int		ft_u(char *s, t_data *data);
int		ft_xX(char *s, t_data *data);
int		ft_p(char *s, t_data *data);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa_precision(int n, t_data *data);
char	*ft_uitoa_precision(unsigned int n, t_data *data);
char	*ft_convert_to_exa(long long int x, t_data *data);
char	*ft_to_upper(char *s, t_data *data);
int		ft_nb_digit(unsigned int x);
char	*flag_minus(char *arg, t_data *data);

#endif
