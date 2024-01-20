/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:30:48 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/20 11:47:20 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	argb_to_int(t_argb color)
{
	int	c;

	c = 0;
	c = c | color.a << 24;
	c = c | color.r << 16;
	c = c | color.g << 8;
	c = c | color.b;
	return (c);
}

static void	draw_julia(t_mlx *mlx)
{
	int		j;
	t_vec	z;

	j = 0;
	while (j < (WIDTH * HEIGHT))
	{
		z.x = (mlx->f.min.x) + ((double)(j % WIDTH) / WIDTH) * mlx->f.r.x;
		z.y = (mlx->f.min.y) + ((double)(j / WIDTH) / HEIGHT) * mlx->f.r.y;
		*(int *)(mlx->img.addr + (j * 4)) = check_convergence(*mlx, z, mlx->f.c)
			* argb_to_int(mlx->f.color);
		j++;
	}
}

static void	draw_mandelbrot(t_mlx *mlx)
{
	int		j;
	t_vec	z;
	t_vec	v;

	v.x = 0;
	v.y = 0;
	j = 0;
	while (j < (WIDTH * HEIGHT))
	{
		z.x = (mlx->f.min.x) + ((double)(j % WIDTH) / WIDTH) * mlx->f.r.x;
		z.y = (mlx->f.min.y) + ((double)(j / WIDTH) / HEIGHT) * mlx->f.r.y;
		*(int *)(mlx->img.addr + (j * 4)) = check_convergence(*mlx, v, z)
			* argb_to_int(mlx->f.color);
		j++;
	}
}

void	render_fractal(t_mlx *mlx, int nb)
{
	if (nb)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.ptr);
	mlx->img.ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.pbits,
			&mlx->img.sline, &mlx->img.e);
	if (mlx->f.id == 1)
		draw_mandelbrot(mlx);
	if (mlx->f.id == 2)
		draw_julia(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
