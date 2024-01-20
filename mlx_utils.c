/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:17:35 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/20 11:50:00 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keypress_handler(int key, t_mlx *mlx)
{
	if (key == 65307 || key == 53)
		stop_connection(mlx);
	if (key == 100)
		set_defaults(mlx);
	render_fractal(mlx, 1);
	return (0);
}

int	stop_connection(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (0);
}

int	zoom(int btn, int x, int y, t_mlx *mlx)
{
	x = WIDTH / 2;
	y = HEIGHT / 2;
	if (btn == 4 || btn == 5)
	{
		if (btn == 4)
			mlx->f.zoom = 2;
		else
			mlx->f.zoom = 0.5;
		mlx->f.mouse.x = mlx->f.min.x + ((double)x / WIDTH) * mlx->f.r.x;
		mlx->f.mouse.y = mlx->f.min.y + ((double)y / HEIGHT) * mlx->f.r.y;
		mlx->f.r.x *= mlx->f.zoom;
		mlx->f.r.y *= mlx->f.zoom;
		mlx->f.max.x = mlx->f.mouse.x + (mlx->f.max.x - mlx->f.mouse.x)
			* mlx->f.zoom;
		mlx->f.min.x = mlx->f.max.x - mlx->f.r.x;
		mlx->f.max.y = mlx->f.mouse.y + (mlx->f.max.y - mlx->f.mouse.y)
			* mlx->f.zoom;
		mlx->f.min.y = mlx->f.max.y - mlx->f.r.y;
		render_fractal(mlx, 1);
	}
	return (0);
}
