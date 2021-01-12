/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:42:17 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 15:07:29 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int		print_hex_precision(t_flags *flags, char *toprint, int len)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (flags->precision > len)
	{
		count += ft_putchar('0');
		flags->precision--;
	}
	while (toprint[i])
		count += ft_putchar(toprint[i++]);
	return (count);
}

int		print_hex_width(int width, int zero)
{
	int	count;

	count = 0;
	while (width-- > 0)
		count += ft_putchar(zero ? '0' : ' ');
	return (count);
}

int		update_hex_flags(t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (flags->precision >= 0 && flags->precision < len)
		flags->precision = len;
	if (flags->precision > 0)
	{
		flags->width -= flags->precision;
		flags->zero = 0;
	}
	else
		flags->width -= len;
	return (count);
}

int		print_hexa(t_flags *flags, unsigned long long toprint, int caps)
{
	int		count;
	int		len;
	char	*toprint_s;
	char	base[16];

	count = 0;
	ft_strlcpy(base, caps ? "0123456789ABCDEF" : "0123456789abcdef", 17);
	toprint_s = ft_ull_base(toprint, base);
	len = (int)ft_strlen(toprint_s);
	if (toprint == 0 && flags->precision == 0)
	{
		return (print_hex_width(flags->width, 0));
	}
	count += update_hex_flags(flags, len);
	if (!flags->minus)
		count += print_hex_width(flags->width, flags->zero);
	count += print_hex_precision(flags, toprint_s, len);
	if (flags->minus)
		count += print_hex_width(flags->width, flags->zero);
	free(toprint_s);
	return (count);
}
