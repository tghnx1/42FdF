/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:09:35 by mkokorev          #+#    #+#             */
/*   Updated: 2023/12/13 19:42:29 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_char(int args);
int	ft_decimal(int args);
int	ft_string(char *args);
int	ft_pointer(unsigned long args);
int	ft_printf(const char *format, ...);
int	ft_uns(unsigned int args);
int	ft_hex_low(unsigned int args);
int	ft_hex_up(unsigned int args);
#endif
