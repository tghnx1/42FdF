/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:02:02 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/10 17:23:45 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef ZOOM
#  define ZOOM 40
# endif

# ifndef SHIFT_X
#  define SHIFT_X 1000
# endif

# ifndef SHIFT_Y
#  define SHIFT_Y -500
# endif

# include "./printf/ft_printf.h"
# include <limits.h>
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct coordinates
{
	int		x;
	int		y;
	int		z;
	int		temp;
	int		end;
	char	*colour;
}	t_coordinate;

typedef struct s_daa
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void			draw_vertikal(t_data *img, t_coordinate xy,
					float y2, int colour);

void			char_arr_free(char **arr);

void			matrix_free(t_coordinate **arr);

int				line_length(char **array);

void			my_mlx_pixel_put(t_data *data, t_coordinate xy, int color);

void			matrix_draw(t_coordinate **matrix, int i, int j, char *argv);

void	def_colour(char *str, t_coordinate *node);

t_coordinate	**z_rotate(t_coordinate	**matrix, char *argv);

void			print_matrix_term(t_coordinate **matrix, char *argv);

int				count_lines(char *argv);

t_coordinate	**y_rotate(t_coordinate	**matrix, char *argv);

void			matrix_line_draw(t_data *img, t_coordinate mat1,
					t_coordinate mat2, int colour);

void			connect_dots(t_data *img, t_coordinate **matrix, char *argv);

int				arr_len(t_coordinate *matrix);

int	str_hex_to_int(char *hex);

#endif
