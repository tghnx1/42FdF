/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:54:25 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 16:09:52 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	horiz_border(t_data *img, t_coordinate matrix1,
			t_coordinate matrix2, t_coordinate center)
{
	if (!(matrix1.colour) && matrix1.x)
	{
		matrix_line_draw(&(*img), matrix2, matrix1,
			center.default_colour);
	}
	else if (matrix1.colour)
	{
		matrix_line_draw(&(*img), matrix2, matrix1,
			str_hex_to_int(matrix2.colour, center.default_colour));
	}
}

void	draw_borders(t_data *img, t_coordinate **matrix,
			t_coordinate center, int i)
{
	int	j;

	j = 0;
	while (j < center.init_length / 100 - 1)
	{
		horiz_border(img, matrix[i][j + 1], matrix[i][j], center);
		j++;
	}
	while (i > 0)
	{
		if (matrix[i - 1][j].x < matrix[i][j].x)
			i = i - 2;
		if (!(matrix[i - 1][j].colour))
			matrix_line_draw(&(*img), matrix[i][j], matrix[i - 1][j],
				center.default_colour);
		else
			matrix_line_draw(&(*img), matrix[i][j], matrix[i - 1][j],
				str_hex_to_int(matrix[i][j].colour, center.default_colour));
		i--;
	}
}

void	lines_draw(t_data *img, t_coordinate matrix1,
			t_coordinate matrix2, t_coordinate center)
{
	if (!(matrix1.colour))
		matrix_line_draw(&(*img), matrix2,
			matrix1, center.default_colour);
	else
		matrix_line_draw(&(*img), matrix2,
			matrix1, str_hex_to_int(matrix2.colour, center.default_colour));
}

void	connect_dots(t_data *img, t_coordinate **matrix, t_coordinate center)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < center.init_width / 100 - 1)
	{
		while (j < center.init_length / 100 - 1)
		{
			lines_draw(img, matrix[i + 1][j], matrix[i][j], center);
			if (matrix[i][j + 1].x < matrix[i][j].x)
				break ;
			lines_draw(img, matrix[i][j + 1], matrix[i][j], center);
			j++;
		}
		j = 0;
		i++;
	}
	draw_borders(img, matrix, center, i);
}
