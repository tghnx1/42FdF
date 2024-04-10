/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:47:33 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/13 18:59:23 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_low(unsigned int args)
{
	int	res;

	res = 0;
	if (args > 15)
		res = res + ft_hex_low(args / 16);
	write(1, &"0123456789abcdef"[args % 16], 1);
	res++;
	return (res);
}
