/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:44:52 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 12:28:49 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	str_hex_to_int(char *hex, int def_col)
{
	int		decimal;
	size_t	i;
	int		num;
	int		digit;

	if (!hex)
		return (def_col);
	i = 0;
	decimal = 0;
	num = 1;
	while (i < ft_strlen(hex))
	{
		if (!((hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= '0'
					&& hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f')))
			return (0);
		if (hex[strlen(hex) - i - 1] >= 'A' && hex[i] <= 'F')
			digit = hex[strlen(hex) - i - 1] - 55;
		else
			digit = hex[strlen(hex) - i - 1] - 48;
		decimal += digit * num;
		num = num * 16;
		i++;
	}
	return (decimal);
}
