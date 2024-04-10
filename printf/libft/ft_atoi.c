/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:39:33 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/05 16:16:15 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spaceskip(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	return ((char *)&nptr[i]);
}

// int	if_max_min(long integer)
// {
// 	if (integer < INT_MIN || integer > INT_MAX)
// 		return (0);
// 	return (integer);
// }

long	ft_atoi(const char *nptr)
{
	long	i;
	long	integer;

	i = 0;
	nptr = ft_spaceskip(nptr);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (ft_isdigit (nptr[i]) == 0)
		return (0);
	integer = nptr[i] - 48;
	while (nptr[i + 1] != '\0' && ft_isdigit((int)nptr[i + 1]))
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			integer = integer * 10 + nptr[i + 1] - 48;
		else
			return (0);
		i++;
	}
	if (*nptr == '-')
		integer = -1 * integer;
	if (nptr[i] == ' ')
		return (0);
	return (integer);
}

/*
int main ()
{
	printf("int: %ld", ft_atoi("2147483648"));
	return (0);
}
*/
