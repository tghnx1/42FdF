/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:19:57 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/13 18:38:54 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuns(unsigned int n, int *count)
{
	if (n <= 9)
	{
		n = '0' + n;
		write(1, &n, 1);
		return ;
	}
	else
	{
		*count = *count + 1;
		ft_putuns((n / 10), count);
		n = '0' + n % 10;
		write(1, &n, 1);
	}
}

int	ft_uns(unsigned int args)
{
	int		count;

	count = 0;
	ft_putuns(args, &count);
	return (count + 1);
}
