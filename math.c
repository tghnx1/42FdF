/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:44:52 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/10 17:26:20 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_coordinate	**z_rotate(t_coordinate	**matrix, char *argv)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i <= count_lines(argv))
	{
		matrix[i][j].temp = matrix[i][j].x;
		matrix[i][j].x = 0.71 * (matrix[i][j].x - matrix[i][j].y);
		matrix[i][j].y = 0.71 * (matrix[i][j].temp + matrix[i][j].y);
		j++;
		if (matrix[i][j - 1].end == 1)
		{
			j = 0;
			i++;
			if (!matrix[i])
				break ;
		}
	}
	return (matrix);
}

t_coordinate	**y_rotate(t_coordinate	**matrix, char *argv)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i <= count_lines(argv))
	{
		matrix[i][j].y = 0.71 * (matrix[i][j].y - matrix[i][j].z);
		j++;
		if (matrix[i][j - 1].end == 1)
		{
			j = 0;
			i++;
			if (!matrix[i])
				break ;
		}
	}
	return (matrix);
}

int	str_hex_to_int(char *hex)
{
	int	colour;

	if (!hex)
		return (16777215);
	
	return (16711680);
}
