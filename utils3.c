/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:09 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 15:28:27 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	center_delta_def(t_coordinate *center, t_coordinate *delta)
{
	center->y_min = center->y_min * center->zoom / 100;
	center->y_max = center->y_max * center->zoom / 100;
	center->x_min = center->x_min * center->zoom / 100;
	center->x_max = center->x_max * center->zoom / 100;
	delta->y_min = abs(center->y_min);
	delta->x_min = abs(center->x_min);
	delta->y_max = abs(center->y_max - center->screen_width);
	delta->x_max = abs(center->x_max - center->screen_length);
}

void	y_last_def(t_coordinate *center, t_coordinate *matrix,
			t_coordinate *delta)
{
	if (center->y_min <= 0)
		matrix->y = matrix->y
			* center->zoom / 100 + delta->y_min;
	else if (center->y_max >= center->screen_width)
		matrix->y = matrix->y
			* center->zoom / 100 - delta->y_max;
	else
		matrix->y = matrix->y * center->zoom / 100;
	if (center->x_min <= 0)
		matrix->x = matrix->x
			* center->zoom / 100 + delta->x_min;
	else if (center->x_max >= center->screen_length)
		matrix->x = matrix->x
			* center->zoom / 100 - delta->x_max;
	else
		matrix->x = matrix->x * center->zoom / 100;
}

void	line_extract(t_coordinate **matrix,
			t_coordinate *center, int *fd, char *line)
{
	char	**str;
	int		i;

	i = 0;
	while (line)
	{
		line = get_next_line(*fd);
		if (!line && !i)
		{
			free(line);
			free(matrix);
			write(1, "File error\n", 11);
			exit(0);
		}
		line = add_n(line);
		str = ft_split(line, ' ');
		free(line);
		matrix[i] = makearr(str, line_length(str), i, center);
		i++;
		char_arr_free(str);
	}
	center->init_width = 100 * (i - 1);
	center->y = center->init_width / 2;
}
