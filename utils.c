/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:31:29 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/10 17:25:25 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	char_arr_free(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	arr_len(t_coordinate *matrix)
{
	int	i;

	i = 0;
	while (matrix[i].end != 1)
		i++;
	i++;
	return (i);
}

void	matrix_free(t_coordinate **arr)
{
	int	i;
	int	j;
	int	mat_len;

	i = 0;
	j = 0;
	while (arr[i])
	{
		mat_len = arr_len(arr[i]);
		while (j < mat_len)
		{
			free(arr[i][j].colour);
			j++;
		}
		j = 0;
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	def_colour(char *str, t_coordinate *node)
{
	char	**z_col;

	{
		z_col = ft_split(str, ',');
		if (!z_col)
		{
			free(str);
			return ;
		}
		(*node).z = ft_atoi(z_col[0]);
		(*node).colour = ft_strdup(z_col[1]);
		if (!(*node).colour)
		{
			free(str);
			char_arr_free(z_col);
			return ;
		}
		char_arr_free(z_col);
	}
}

void	print_matrix_term(t_coordinate **matrix, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= count_lines(argv))
	{
		printf("%d;%d  ", matrix[i][j].x, matrix[i][j].y);
		j++;
		if (matrix[i][j - 1].end == 1)
		{
			j = 0;
			i++;
			if (!matrix[i])
				break ;
		}
		printf("matrix[%d] : %p\n", i, matrix[i]);
	}
	printf("matrix[%d] : %p\n", i, matrix[i]);
}
