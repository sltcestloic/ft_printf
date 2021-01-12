/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:09:06 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 10:50:09 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		print_int_precision(t_flags *flags, int toprint, int len)
{
	int		count;
	char	*toprint_s;
	int		i;

	count = 0;
	i = 0;
	while (flags->precision > len)
	{
		if (toprint < 0)
		{
			toprint *= -1;
			count += ft_putchar('-');
		}
		count += ft_putchar('0');
		flags->precision--;
	}
	toprint_s = ft_itoa(toprint);
	while (toprint_s[i])
		count += ft_putchar(toprint_s[i++]);
	return (count);
}

int		print_int_width(int width, int zero, int minus)
{
	int	count;

	count = 0;
	while (width-- - minus > 0)
		count += ft_putchar(zero ? '0' : ' ');
	return (count);
}

int		update_int_flags(t_flags *flags, int *toprint, int len)
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
	if (flags->width > 0 && flags->zero)
	{
		if (*toprint < 0)
		{
			*toprint *= -1;
			count += ft_putchar('-');
		}
	}
	return (count);
}

int		print_int(t_flags *flags, int toprint)
{
	int		count;
	int		len;
	int		minus;

	count = 0;
	len = (int)ft_intlen(toprint);
	minus = 0;
	if (toprint < 0)
	{
		len--;
		minus = 1;
	}
	if (toprint == 0 && flags->precision == 0)
		return (print_int_width(flags->width, 0, toprint < 0));
	count += update_int_flags(flags, &toprint, len);
	if (!flags->minus)
		count += print_int_width(flags->width, flags->zero, minus);
	count += print_int_precision(flags, toprint, len);
	if (flags->minus)
		count += print_int_width(flags->width, flags->zero, minus);
	return (count);
}
