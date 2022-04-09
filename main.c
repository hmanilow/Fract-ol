/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:50 by hmanilow          #+#    #+#             */
/*   Updated: 2022/04/09 17:41:52 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	struct_init(t_fract *f, char *type)
{
	f->max_x = 1;
	f->min_x = -2;
	f->max_y = 1;
	f->min_y = -1;
	f->max_iter = 50;
	f->type = 'm';
	init_grad(f);
	f->rog = 0;
	f->mov = 1;
	if (!ft_strncmp(type, "Julia"))
	{
		f->max_x += 1;
		f->type = 'j';
	}
	if (!ft_strncmp(type, "Ship"))
	{
		f->max_x += 1;
		f->max_y -= 0.5;
		f->min_y -= 0.5;
		f->type = 's';
	}
}

void	ft_refresh(t_base *w)
{
	int			i;
	int			j;
	t_ip		cor;
	static t_dp	cord;

	i = -1;
	if (w->f.mov)
	{
		mlx_mouse_get_pos(w->win, &cor.x, &cor.y);
		cord.x = w->f.min_x + (double)cor.x / 1920 * (w->f.max_x - w->f.min_x);
		cord.y = w->f.min_y + (double)cor.y / 1080 * (w->f.max_y - w->f.min_y);
	}
	while (i++ < 1919)
	{
		j = -1;
		while (j++ < 1079)
		{
			if (w->f.type == 'm')
				m_print(w, i, j);
			else if (w->f.type == 's')
				s_print(w, i, j);
			else if (w->f.type == 'j')
				j_print(w, i, j, cord);
		}
	}
}

int	ft_rendering(t_base *w)
{
	w->data.img = mlx_new_image(w->mlx, 1920, 1080);
	w->data.addr = mlx_get_data_addr(w->data.img, \
	&(w->data.bits_per_pixel), &(w->data.line_length), &(w->data.endian));
	ft_refresh(w);
	mlx_put_image_to_window(w->mlx, w->win, w->data.img, 0, 0);
	mlx_destroy_image(w->mlx, w->data.img);
	return (0);
}

int	e_exit(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_base	w;

	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot") || !ft_strncmp(argv[1], "Julia")
			|| !ft_strncmp(argv[1], "Ship"))
		{
			w = *(t_base *)malloc(sizeof(t_base));
			w.mlx = (void *)malloc(sizeof(void *));
			w.win = (void *)malloc(sizeof(void *));
			w.mlx = mlx_init();
			w.win = mlx_new_window(w.mlx, 1920, 1080, "fractol");
			struct_init(&w.f, argv[1]);
			mlx_loop_hook(w.mlx, &ft_loop_hook, &w);
			mlx_loop(w.mlx);
		}
		else
			write(1, "List of available fractols:\n-Mandelbrot\n-Julia\n-Ship\n", \
			54);
	}
	else
		write(1, "List of available fractols:\n-Mandelbrot\n-Julia\n-Ship\n", \
			54);
	return (0);
}
