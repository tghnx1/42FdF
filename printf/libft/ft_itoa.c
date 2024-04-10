/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:43:11 by mkokorev          #+#    #+#             */
/*   Updated: 2023/11/27 15:43:11 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenarr(int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_alloc(char *arr, int *len, int n)
{
	if (n == 0)
	{
		arr = ft_calloc(2, sizeof(char));
		if (!arr)
			return (0);
		*arr = '0';
		return (arr);
	}
	if (n == -2147483648)
	{
		arr = ft_strdup("-2147483648");
		if (!arr)
			return (0);
		return (arr);
	}
	*len = ft_lenarr(n);
	if (n < 0)
		arr = (char *)malloc((*len + 1) * sizeof(char) + 1);
	else
		arr = (char *)malloc((*len + 1) * sizeof(char));
	if (!arr)
		return (0);
	return (arr);
}

char	*ft_abs(char *arr, int *n)
{
	*n = -1 * (*n);
	*arr = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		l;
	int		length;

	arr = NULL;
	arr = ft_alloc(arr, &length, n);
	if (!arr)
		return (NULL);
	if (n == -2147483648 || n == 0)
		return (arr);
	l = 0;
	if (n < 0)
		ft_abs(arr, &n);
	else
		l = 1;
	arr[length + 1 - l] = '\0';
	while (length > 0)
	{
		*(arr + length - l) = '0' + n % 10;
		n = n / 10;
		length--;
	}
	return (arr);
}
