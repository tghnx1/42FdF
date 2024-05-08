/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:02:51 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 16:03:41 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	count_lines(char *argv)
{
	int		fd;
	int		i;
	char	*line;

	line = argv;
	fd = open(argv, O_RDONLY);
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		i++;
		free(line);
	}
	i--;
	close(fd);
	return (i);
}

t_coordinate	*makearr(char **str, int num, int y, t_coordinate *center)
{
	t_coordinate	*arr;

	if (!str)
		return (0);
	arr = ft_calloc(num + 1, sizeof(t_coordinate));
	if (!arr)
		return (0);
	coord_def(str, arr, y, center);
	return (arr);
}

int	line_length(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

t_coordinate	**matrix_def(char *argv, t_coordinate *center)
{
	char			*line;
	int				fd;
	t_coordinate	**matrix;

	line = argv;
	fd = open(argv, O_RDONLY);
	if (!fd)
		return (0);
	matrix = ft_calloc(count_lines(argv) + 2, sizeof(t_coordinate *));
	if (!matrix)
		return (0);
	line_extract(matrix, center, &fd, line);
	close(fd);
	return (matrix);
}

int	main(int argc, char **argv)
	{
	t_coordinate	**matrix;
	t_coordinate	center;

	if (argc != 2)
	{
		write(1, "Wrong number of arguments!\n", 27);
		return (0);
	}
	center.y_min = INT_MAX;
	center.y_max = 0;
	center.x_min = INT_MAX;
	center.x_max = 0;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	center.screen_length = 1920;
	center.screen_width = 1080;
	center.default_colour = 3381657;
	matrix = matrix_def(argv[1], &center);
	if (!matrix)
		return (0);
	zoom_def(&center);
	move_mat(matrix, &center);
	matrix_draw(matrix, center);
	return (0);
}
