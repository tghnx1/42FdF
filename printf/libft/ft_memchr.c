/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:27:25 by mkokorev          #+#    #+#             */
/*   Updated: 2023/11/16 18:14:45 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*s1;

	i = 0;
	s1 = s;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
		{
			return ((void *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
