/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:52:14 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 13:17:26 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	reset_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->minus = 0;
	flags->type = 0;
	flags->width = 0;
	flags->zero = 0;
	return (*flags);
}

int		parse_type(const char *input, int i, t_flags *flags, va_list params)
{
	while (is_valid_type(input[i]) || is_valid_flag(input[i]) ||
	ft_isdigit(input[i]))
	{
		if (input[i] == '0')
		{
			handle_zero_flag(flags);
			i++;
		}
		if (input[i] == '.')
			i = handle_precision_flag(flags, input, ++i);
		if (input[i] == '*')
			handle_wildcard_flag(flags, params);
		else if (input[i] == '-')
			handle_minus_flag(flags);
		else if (ft_isdigit(input[i]))
			i = handle_width_flag(flags, input, i);
		if (is_valid_type(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		print_input(const char *input, va_list params)
{
	size_t	i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (input[i])
	{
		flags = reset_flags(&flags);
		if (input[i] == '%' && input[i + 1])
		{
			i = parse_type(input, ++i, &flags, params);
			count += print_type(&flags, params);
		}
		else if (input[i] != '%')
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

int		ft_printf(const char *input, ...)
{
	va_list	params;
	int		writtenchars;

	va_start(params, input);
	writtenchars = print_input(input, params);
	va_end(params);
	return (writtenchars);
}
