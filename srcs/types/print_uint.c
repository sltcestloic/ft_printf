/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:54:18 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 13:17:15 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		print_uint_precision(t_flags *flags, unsigned int toprint, int len)
{
	int		count;
	char	*toprint_s;
	int		i;

	count = 0;
	i = 0;
	while (flags->precision > len)
	{
		count += ft_putchar('0');
		flags->precision--;
	}
	toprint_s = ft_uitoa(toprint);
	while (toprint_s[i])
		count += ft_putchar(toprint_s[i++]);
	return (count);
}

int		print_uint_width(int width, int zero)
{
	int	count;

	count = 0;
	while (width-- > 0)
		count += ft_putchar(zero ? '0' : ' ');
	return (count);
}

int		update_uint_flags(t_flags *flags, int len)
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

int		print_uint(t_flags *flags, unsigned int toprint)
{
	int		count;
	int		len;

	count = 0;
	len = (int)ft_intlen(toprint);
	if (toprint == 0 && flags->precision == 0)
		return (print_uint_width(flags->width, 0));
	count += update_uint_flags(flags, len);
	if (!flags->minus)
		count += print_uint_width(flags->width, flags->zero);
	count += print_uint_precision(flags, toprint, len);
	if (flags->minus)
		count += print_uint_width(flags->width, flags->zero);
	return (count);
}
