/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:36:04 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 13:17:06 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_char(t_flags *flags, int toprint)
{
	int	count;

	count = 0;
	if (flags->width > 1)
	{
		if (!flags->minus)
			while (flags->width-- > 1)
				count += ft_putchar(flags->zero ? '0' : ' ');
		count += ft_putchar((char)toprint);
		if (flags->minus)
			while (flags->width-- > 1)
				count += ft_putchar(flags->zero ? '0' : ' ');
	}
	else
		count += ft_putchar((char)toprint);
	return (count);
}

int	print_string_precision(t_flags *flags, char *toprint)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (flags->precision == -1)
		while (toprint[i])
			count += ft_putchar(toprint[i++]);
	else
		while (flags->precision-- > 0 && toprint[i])
			count += ft_putchar(toprint[i++]);
	return (count);
}

int	print_string(t_flags *flags, char *toprint)
{
	int		count;
	int		len;

	count = 0;
	if (!toprint)
		toprint = "(null)";
	len = (int)ft_strlen(toprint);
	if (flags->precision >= 0 && len > flags->precision)
		len = flags->precision;
	if (flags->width > len)
	{
		if (!flags->minus)
			while (flags->width-- > len)
				count += ft_putchar(flags->zero ? '0' : ' ');
		count += print_string_precision(flags, toprint);
		if (flags->minus)
			while (flags->width-- > len)
				count += ft_putchar(flags->zero ? '0' : ' ');
	}
	else
		count += print_string_precision(flags, toprint);
	return (count);
}
