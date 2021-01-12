/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:25:12 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 13:17:21 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_zero_flag(t_flags *flags)
{
	if (!flags->minus)
		flags->zero = 1;
}

int		handle_precision_flag(t_flags *flags, const char *input, int i)
{
	if (!ft_isalnum(input[i]))
	{
		flags->precision = -2;
		return (i);
	}
	flags->precision = 0;
	while (ft_isdigit(input[i]))
	{
		flags->precision = flags->precision * 10 + input[i] - 48;
		i++;
	}
	return (i);
}

void	handle_wildcard_flag(t_flags *flags, va_list params)
{
	if (flags->precision == -2)
		flags->precision = va_arg(params, int);
	else
	{
		flags->width = va_arg(params, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			handle_minus_flag(flags);
		}
	}
}

void	handle_minus_flag(t_flags *flags)
{
	if (flags->zero > 0)
		flags->zero = 0;
	flags->minus = 1;
}

int		handle_width_flag(t_flags *flags, const char *input, int i)
{
	while (ft_isdigit(input[i]))
		flags->width = flags->width * 10 + input[i++] - 48;
	return (i - 1);
}
