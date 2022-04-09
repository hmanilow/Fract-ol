/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:22 by hmanilow          #+#    #+#             */
/*   Updated: 2022/04/09 17:41:25 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int btn, t_base *w)
{
	if (btn == 123 || btn == 124)
		lr_key(btn, w);
	else if (btn == 125 || btn == 126)
		ud_key(btn, w);
	else if (btn == 40)
		w->f.rog = !w->f.rog;
	else if (btn == 69)
		w->f.max_iter++;
	else if (btn == 78)
		w->f.max_iter--;
	else if (btn == 53)
		e_exit();
	return (0);
}

int	ft_mouse_hook(int btn, int x, int y, t_fract *f)
{
	if (btn == 5)
		ft_scroll_down(x, y, f);
	else if (btn == 4)
		ft_scroll_up(x, y, f);
	else if (btn == 1)
		f->mov = !f->mov;
	return (0);
}

int	ft_loop_hook(t_base *w)
{
	ft_rendering(w);
	mlx_hook(w->win, 17, 0, e_exit, w);
	mlx_key_hook(w->win, &ft_key_hook, w);
	mlx_mouse_hook(w->win, &ft_mouse_hook, &w->f);
	return (0);
}
