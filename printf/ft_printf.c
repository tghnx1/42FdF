/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:51:30 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/13 20:49:33 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list	args)
{
	if (c == 's')
		return (ft_string(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_decimal(va_arg(args, int)));
	if (c == 'c')
		return (ft_char(va_arg(args, int)));
	if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long long)) + 2);
	if (c == 'u')
		return (ft_uns(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_hex_low(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_hex_up(va_arg(args, unsigned int)));
	if (c == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += ft_check(*(format + 1), args);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count ++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
