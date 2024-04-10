/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:17:59 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/05 19:17:59 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		i;

	i = 0;
	arr = ft_strdup(s);
	if (!arr || !s)
		return (0);
	while (arr[i])
	{
		arr[i] = (*f)(i, arr[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
