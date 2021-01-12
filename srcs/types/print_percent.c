/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:58:12 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 13:19:01 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		print_percent(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->width > 1)
	{
		if (!flags->minus)
			while (flags->width-- > 1)
				count += ft_putchar(flags->zero ? '0' : ' ');
		count += ft_putchar('%');
		if (flags->minus)
			while (flags->width-- > 1)
				count += ft_putchar(flags->zero ? '0' : ' ');
	}
	else
		count += ft_putchar('%');
	return (count);
}
