/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:20:33 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/13 19:25:45 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *args)
{
	if (!args)
		return (write(1, "(null)", 6));
	ft_putstr_fd(args, 1);
	return (ft_strlen(args));
}
