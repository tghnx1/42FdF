/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:05:25 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/04 14:09:02 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_basecheck(const char *big, const char *little, int len)
{
	if (!len && !ft_len(little))
		return ((char *)big);
	if (ft_len(little) > ft_len(big))
		return (0);
	return ((char *)big);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((!len && !ft_len(little)) || (ft_len(little) > ft_len(big)))
		return (ft_basecheck(big, little, len));
	while (i < len)
	{
		while (little[j] && i + j < len)
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		else
		{
			i++;
			j = 0;
		}
	}
	return ((char *)0);
}
