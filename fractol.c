/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:42:07 by aabidar           #+#    #+#             */
/*   Updated: 2024/01/20 11:55:28 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_mlx *mlx)
{
	mlx->f.r.x = 4;
	mlx->f.r.y = 4;
	mlx->f.max.x = 2;
	mlx->f.max.y = 2;
	mlx->f.min.y = -2;
	mlx->f.min.x = -2;
	mlx->f.max_i = 100;
	mlx->f.radius = 2;
	mlx->f.zoom = 1;
	mlx->f.color.a = 1;
	mlx->f.color.r = 21;
	mlx->f.color.g = 0;
	mlx->f.color.b = 51;
}

void	show_help(void)
{
	ft_putstr("Fract-ol\n");
	ft_putstr("---------------------------\n");
	ft_putstr("Usage: ./fractol [fractal_name] ");
	ft_putstr("[constant_x (for Julia)] [constant_y (for Julia)]\n");
	ft_putstr("Fractal Types:\n\t");
	ft_putstr("Mandelbrot/m - Mandelbrot Set\n\tJulia/j - Julia Set\n");
	ft_putstr("----------------------------\n");
	ft_putstr("Examples:\n\t./fract-ol Mandelbrot\n\t");
	ft_putstr("./fract-ol Julia -0.8 0.156 \n");
	ft_putstr("To quit:\n\tPress ESC button.\n");
	ft_putstr("\tClick on 'X' at the top of the window\n");
	ft_putstr("To move:\n\tUse the arrow keys.\n");
	ft_putstr("To zoom:\n\tUse the mouse wheel.\n");
	ft_putstr("To change color:\n\tUse the R(red), G(green), B(blue) keys.\n");
	ft_putstr("To go back to default:\n\tPress D.\n");
	exit(1);
}

int	check_params(t_mlx *mlx, int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "m"))
			return (1);
	}
	else if (ac == 4 && (!ft_strcmp(av[1], "j") || !ft_strcmp(av[1], "Julia")))
	{
		if (check_constant(av[2]) && check_constant(av[3]))
		{
			mlx->f.c.x = ft_atof(av[2]);
			mlx->f.c.y = ft_atof(av[3]);
			return (2);
		}
	}
	show_help();
	return (-1);
}

void	create_window(t_mlx *mlx, char *title)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, title);
	if (!mlx->win_ptr)
	{
		free(mlx->mlx_ptr);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	set_defaults(&mlx);
	mlx.f.id = check_params(&mlx, ac, av);
	create_window(&mlx, av[1]);
	render_fractal(&mlx, 0);
	mlx_key_hook(mlx.win_ptr, keypress_handler, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0L, stop_connection, &mlx);
	mlx_hook(mlx.win_ptr, 4, 1L << 2, zoom, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
