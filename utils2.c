/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:29:35 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 14:27:14 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*add_n(char *line)
{
	char	*temp;
	int		len;

	if (line)
	{
		len = ft_strlen(line);
		if (line[len - 2] == ' ')
			line[len - 2] = '\n';
		if (line[len - 1] != '\n')
		{
			temp = line;
			line = ft_strjoin(line, "\n");
			free(temp);
		}
	}
	return (line);
}

void	zoom_def(t_coordinate *center)
{
	center->zoom = 40;
	center->last_width = abs(center->y_max - center->y_min);
	center->last_length = abs(center->x_max - center->x_min);
	while (center->zoom > 1)
	{
		if (center->last_length * center->zoom / 100 > center->screen_length
			|| center->last_width * center->zoom / 100 > center->screen_width)
			center->zoom = center->zoom / 2;
		else
			break ;
	}
	center->last_length = center->last_length * center->zoom / 100;
	center->last_width = center->last_width * center->zoom / 100;
}

void	xy_max_min(int x, int y, t_coordinate *center)
{
	if (x < center->x_min)
		center->x_min = x;
	if (x > center->x_max)
		center->x_max = x;
	if (y < center->y_min)
		center->y_min = y;
	if (y > center->y_max)
		center->y_max = y;
}

void	coord_def(char **str, t_coordinate *arr, int y, t_coordinate *center)
{
	int	i;

	i = 0;
	while (str[i])
	{
		arr[i].y = y * 100;
		arr[i].x = i * 100;
		arr[i].temp = arr[i].x;
		arr[i].x = 0.71 * (arr[i].x - arr[i].y);
		if (ft_strchr(str[i], ','))
			def_colour(str[i], &arr[i]);
		else
		{
			arr[i].z = 100 * ft_atoi(str[i]);
			arr[i].colour = NULL;
		}
		arr[i].y = 0.71 * (0.71 * (arr[i].temp + arr[i].y)
				- arr[i].z);
		xy_max_min(arr[i].x, arr[i].y, center);
		i++;
	}
	arr[i - 1].end = 1;
	center->init_length = 100 * i;
	center->x = center->init_length / 2;
}

void	move_mat(t_coordinate **matrix, t_coordinate *center)
{
	int				i;
	int				j;
	t_coordinate	delta;

	i = 0;
	j = 0;
	center_delta_def(center, &delta);
	while (i < center->init_width / 100)
	{
		while (j < center->init_length / 100)
		{
			y_last_def(center, &matrix[i][j], &delta);
			j++;
		}
		j = 0;
		i++;
	}
}
