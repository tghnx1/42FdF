/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:54:25 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/10 17:12:44 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	connect_dots(t_data *img, t_coordinate **matrix, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_lines(argv) - 1)
	{
		while (j < arr_len(matrix[i]) - 1)
		{
			matrix_line_draw(&(*img), matrix[i][j],
				matrix[i][j + 1], str_hex_to_int(matrix[i][j].colour));
			matrix_line_draw(&(*img), matrix[i][j],
				matrix[i + 1][j], str_hex_to_int(matrix[i][j].colour));
			j++;
		}
		j = 0;
		i++;
	}
	//void draw_borders(t_data *img, t_coordinate **matrix, char *argv)
	while (j < arr_len(matrix[i]) - 1)
	{
		matrix_line_draw(&(*img), matrix[i][j], matrix[i][j + 1], str_hex_to_int(matrix[i][j].colour));
		j++;
	}
	while (i > 0)
	{
		matrix_line_draw(&(*img), matrix[i][j], matrix[i - 1][j], str_hex_to_int(matrix[i][j].colour));
		i--;
	}
}
