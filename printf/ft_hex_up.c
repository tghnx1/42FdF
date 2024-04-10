/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:01:56 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/13 19:03:56 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_up(unsigned int args)
{
	int	res;

	res = 0;
	if (args > 15)
		res = res + ft_hex_up(args / 16);
	write(1, &"0123456789ABCDEF"[args % 16], 1);
	res++;
	return (res);
}
