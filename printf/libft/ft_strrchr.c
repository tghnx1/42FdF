/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:08:26 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/05 18:24:41 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_sln(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cstr;

	i = ft_sln(s);
	cstr = (char) c;
	while (i >= 0)
	{
		if (s[i] == cstr || s[i] == cstr)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (*s == cstr)
		return ((char *)s);
	return (NULL);
}
