/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:02:02 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 15:22:59 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./printf/ft_printf.h"
# include <limits.h>
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>

typedef struct coordinates
{
	int		x;
	int		y;
	int		z;
	int		temp;
	int		end;
	int		zoom;
	int		init_width;
	int		init_length;
	int		last_width;
	int		last_length;
	int		y_min;
	int		y_max;
	int		x_min;
	int		x_max;
	int		delta;
	int		screen_width;
	int		screen_length;
	int		default_colour;
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

typedef struct s_vars
{
	void			*mlx;
	void			*img;
	void			*win;
	t_coordinate	**matrix;
}				t_vars;

void			draw_vertikal(t_data *img, t_coordinate xy,
					int y2, int colour);

void			char_arr_free(char **arr);

void			matrix_free(t_coordinate **arr);

int				line_length(char **array);

void			my_mlx_pixel_put(t_data *data, t_coordinate xy, int color);

void			matrix_draw(t_coordinate **matrix, t_coordinate center);

void			def_colour(char *str, t_coordinate *node);

void			print_matrix_term(t_coordinate **matrix, char *argv);

int				count_lines(char *argv);

void			matrix_line_draw(t_data *img, t_coordinate mat1,
					t_coordinate mat2, int colour);

void			connect_dots(t_data *img, t_coordinate **matrix,
					t_coordinate center);

int				arr_len(t_coordinate *matrix);

int				str_hex_to_int(char *hex, int def_col);

char			*add_n(char *line);

void			coord_def(char **str, t_coordinate *arr, int y,
					t_coordinate *center);

void			zoom_def(t_coordinate *center);

void			move_mat(t_coordinate **matrix, t_coordinate *center);

void			center_delta_def(t_coordinate *center, t_coordinate *delta);

void			y_last_def(t_coordinate *center, t_coordinate *matrix,
					t_coordinate *delta);

int				handle_input(int keysym, t_vars *data);

int				x_close(t_vars *data);

void			line_extract(t_coordinate **matrix,
					t_coordinate *center, int *fd, char *line);

t_coordinate	*makearr(char **str, int num, int y, t_coordinate *center);
#endif
