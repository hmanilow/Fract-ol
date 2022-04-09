/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:45 by hmanilow          #+#    #+#             */
/*   Updated: 2022/04/09 17:41:47 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_scroll_down(int x, int y, t_fract *f)
{
	double	a;
	double	b;
	double	temp;

	a = x / 1920.0;
	b = y / 1080.0;
	temp = (f->max_x - f->min_x) * a * 0.15;
	f->max_x -= (f->max_x - f->min_x) * (1.0 - a) * 0.15;
	f->min_x += temp;
	temp = (f->max_y - f->min_y) * b * 0.15;
	f->max_y -= (f->max_y - f->min_y) * (1.0 - b) * 0.15;
	f->min_y += temp;
}

void	ft_scroll_up(int x, int y, t_fract *f)
{
	double	a;
	double	b;
	double	temp;

	a = x / 1920.0;
	b = y / 1080.0;
	temp = (f->max_x - f->min_x) * a * 0.15;
	f->max_x += (f->max_x - f->min_x) * (1.0 - a) * 0.15;
	f->min_x -= temp;
	temp = (f->max_y - f->min_y) * b * 0.15;
	f->max_y += (f->max_y - f->min_y) * (1.0 - b) * 0.15;
	f->min_y -= temp;
}

int	ud_key(int boutton, t_base *w)
{
	double	temp;

	temp = 0.1 * (w->f.max_y - w->f.min_y);
	if (boutton == 126)
		temp *= -1;
	w->f.max_y += temp;
	w->f.min_y += temp;
	return (0);
}

int	lr_key(int boutton, t_base *w)
{
	double	temp;

	temp = 0.1 * (w->f.max_x - w->f.min_x);
	if (boutton == 123)
		temp *= -1;
	w->f.max_x += temp;
	w->f.min_x += temp;
	return (0);
}
