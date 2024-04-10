/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:02:51 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/10 17:25:20 by mkokorev         ###   ########.fr       */
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

t_coordinate	*makearr(char **str, int num, int y)
{
	int				i;
	t_coordinate	*arr;

	if (!str)
		return (0);
	arr = ft_calloc(num, sizeof(t_coordinate));
	if (!arr)
		return (0);
	i = 0;
	while (str[i])
	{
		arr[i].y = SHIFT_Y + y * ZOOM;
		arr[i].x = SHIFT_X + i * ZOOM;
		if (ft_strchr(str[i], ','))
			def_colour(str[i], &arr[i]);
		else
			arr[i].z = ft_atoi(str[i]);
		i++;
	}
	arr[i - 1].end = 1;
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

t_coordinate	**matrix_def(char *argv)
{
	char			*line;
	int				fd;
	char			**str;
	int				i;
	t_coordinate	**matrix;

	line = argv;
	fd = open(argv, O_RDONLY);
	i = 0;
	matrix = ft_calloc(count_lines(argv) + 2, sizeof(t_coordinate *));
	if (!matrix)
		return (0);
	while (line)
	{
		line = get_next_line(fd);
		str = ft_split(line, ' ');
		free(line);
		matrix[i] = makearr(str, line_length(str), i);
		i++;
		char_arr_free(str);
	}
	matrix[i] = NULL;
	close(fd);
	return (matrix);
}

int	main(int argc, char **argv)
	{
	t_coordinate	**matrix;

	matrix = matrix_def(argv[1]);
	z_rotate(matrix, argv[1]);
	y_rotate(matrix, argv[1]);
	printf("colour[0][0] = %s\n", matrix[0][0].colour);
	//print_matrix_term(matrix, argv[1]);
	matrix_draw(matrix, 0, 0, argv[1]);
	matrix_free(matrix);
	return (0);
}
