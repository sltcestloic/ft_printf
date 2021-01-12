/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:54:45 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 13:19:15 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		print_pointer_precision(t_flags *flags, char *toprint)
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

int		print_pointer_width(t_flags *flags, char *toprint, int len)
{
	int	count;

	count = 0;
	if (flags->precision >= 0 && len > flags->precision)
		len = flags->precision;
	if (flags->width > len)
	{
		if (!flags->minus)
			while (flags->width-- > len)
				count += ft_putchar(flags->zero ? '0' : ' ');
		count += print_pointer_precision(flags, toprint);
		if (flags->minus)
			while (flags->width-- > len)
				count += ft_putchar(flags->zero ? '0' : ' ');
	}
	else
		count += print_pointer_precision(flags, toprint);
	return (count);
}

int		print_pointer(t_flags *flags, unsigned long long toprint)
{
	int		count;
	int		len;
	char	*toprint_s;
	char	*toprint_hex;
	char	base[16];

	count = 0;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (toprint == 0)
		return (print_pointer_width(flags, "0x0", 3));
	toprint_hex = ft_ull_base(toprint, base);
	toprint_s = ft_strjoin("0x", toprint_hex);
	free(toprint_hex);
	len = (int)ft_strlen(toprint_s);
	count += print_pointer_width(flags, toprint_s, len);
	free(toprint_s);
	return (count);
}
