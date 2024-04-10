/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:05:36 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/20 15:25:15 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long args)
{
	int				res;

	res = 0;
	if (args > 15)
		res = res + ft_hex(args / 16);
	write(1, &"0123456789abcdef"[args % 16], 1);
	res++;
	return (res);
}

int	ft_pointer(unsigned long args)
{
	if (!args)
		return (write(1, "(nil)", 5) - 2);
	else
		write(1, "0x", 2);
	return (ft_hex(args));
}
