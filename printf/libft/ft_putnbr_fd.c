/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:07:43 by mkokorev          #+#    #+#             */
/*   Updated: 2023/11/28 21:07:43 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n <= 9)
	{
		n = '0' + n;
		write(fd, &n, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		n = '0' + n % 10;
		write(fd, &n, 1);
	}
}
