/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:06:20 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/04 14:16:18 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen((char *)s))
	{
		substr = ft_calloc(1, 1);
		if (!substr)
			return (0);
		return (substr);
	}
	if (len > (ft_strlen((char *)s) - start))
		len = ft_strlen((char *)s) - start;
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
