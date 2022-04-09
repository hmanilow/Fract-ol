/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:40 by hmanilow          #+#    #+#             */
/*   Updated: 2022/04/09 17:41:43 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_print(t_base *w, double iter, int i, int j)
{
	if (!w->f.rog)
	{
		if (iter < w->f.max_iter)
			ft_mlx_pixel_put(&w->data, i, j, w->f.gradg[(int)iter % 6]);
		else
			ft_mlx_pixel_put(&w->data, i, j, 0x0);
	}
	else
	{
		if (iter < w->f.max_iter)
			ft_mlx_pixel_put(&w->data, i, j, w->f.gradr[(int)iter % 3]);
		else
			ft_mlx_pixel_put(&w->data, i, j, 0x0);
	}
}

void	m_print(t_base *w, int i, int j)
{
	double	temp;
	t_dp	def;
	t_dp	con;
	double	iter;

	con.x = w->f.min_x + (double)i / 1920 * (w->f.max_x - w->f.min_x);
	con.y = w->f.min_y + (double)j / 1080 * (w->f.max_y - w->f.min_y);
	def.x = 0;
	def.y = 0;
	iter = 0;
	while (def.x * def.x + def.y * def.y < 4 && iter < w->f.max_iter)
	{
		temp = def.x * def.x - def.y * def.y + con.x;
		def.y = 2 * def.x * def.y + con.y;
		def.x = temp;
		iter++;
	}
	ft_print(w, iter, i, j);
}

void	j_print(t_base *w, int i, int j, t_dp cord)
{
	double	temp;
	t_dp	def;
	t_dp	con;
	double	iter;

	con.x = cord.x;
	con.y = cord.y;
	def.x = w->f.min_x + (double)i / 1920 * (w->f.max_x - w->f.min_x);
	def.y = w->f.min_y + (double)j / 1080 * (w->f.max_y - w->f.min_y);
	iter = 0;
	while (def.x * def.x + def.y * def.y < 4 && iter < w->f.max_iter)
	{
		temp = def.x * def.x - def.y * def.y + con.x;
		def.y = 2 * def.x * def.y + con.y;
		def.x = temp;
		iter++;
	}
	ft_print(w, iter + 1, i, j);
}

void	s_print(t_base *w, int i, int j)
{
	double	temp;
	t_dp	def;
	t_dp	con;
	double	iter;

	con.x = w->f.min_x + (double)i / 1920 * (w->f.max_x - w->f.min_x);
	con.y = w->f.min_y + (double)j / 1080 * (w->f.max_y - w->f.min_y);
	def.x = 0;
	def.y = 0;
	iter = 0;
	while (def.x * def.x + def.y * def.y < 4 && iter < w->f.max_iter)
	{
		temp = def.x * def.x - def.y * def.y + con.x;
		def.y = fabs(2 * def.x * def.y) + con.y;
		def.x = temp;
		iter++;
	}
	ft_print(w, iter, i, j);
}
