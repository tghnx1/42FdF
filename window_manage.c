/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:20:03 by mkokorev          #+#    #+#             */
/*   Updated: 2024/04/24 11:25:24 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	handle_input(int keysym, t_vars *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data -> mlx);
		free(data->mlx);
		matrix_free(data->matrix);
		exit(0);
	}
	return (1);
}

int	x_close(t_vars *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data -> mlx);
	free(data->mlx);
	matrix_free(data->matrix);
	exit(0);
}
