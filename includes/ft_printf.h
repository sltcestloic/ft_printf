/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:37:54 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/12 10:43:51 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "../libft/libft.h"

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				precision;
}					t_flags;

int		ft_printf(const char *input, ...) __attribute__((format(printf,1,2)));
int		ft_putchar(char c);
int		is_valid_type(char c);
int		is_valid_flag(char c);
void	handle_zero_flag(t_flags *flags);
int		handle_precision_flag(t_flags *flags, const char *input, int i);
void	handle_wildcard_flag(t_flags *flags, va_list params);
int		handle_width_flag(t_flags *flags, const char *input, int i);
void	handle_minus_flag(t_flags *flags);
int		print_type(t_flags *flags, va_list params);
int		print_string(t_flags *flags, char *toprint);
int		print_char(t_flags *flags, int toprint);
int		print_int(t_flags *flags, int toprint);
int		print_percent(t_flags *flags);
int		print_uint(t_flags *flags, unsigned int toprint);
int		print_pointer(t_flags *flags, unsigned long long toprint);
int		print_hexa(t_flags *flags, unsigned long long toprint, int caps);

#endif
