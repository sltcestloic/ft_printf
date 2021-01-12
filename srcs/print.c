/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:30:58 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 15:10:27 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_type(t_flags *flags, va_list params)
{
	char	type;
	int		count;

	type = (char)flags->type;
	count = 0;
	if (flags->precision < -1)
		flags->precision = -1;
	if (type == 's')
		count = print_string(flags, va_arg(params, char *));
	else if (type == 'c')
		count = print_char(flags, va_arg(params, int));
	else if (type == 'd' || type == 'i')
		count = print_int(flags, va_arg(params, int));
	else if (type == '%')
		count = print_percent(flags);
	else if (type == 'u')
		count = print_uint(flags, va_arg(params, unsigned int));
	else if (type == 'p')
		count = print_pointer(flags, va_arg(params, unsigned long long));
	else if (type == 'x' || type == 'X')
		count = print_hexa(flags, va_arg(params, unsigned int),\
		type == 'X');
	return (count);
}
