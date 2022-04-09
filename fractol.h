/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:35 by hmanilow          #+#    #+#             */
/*   Updated: 2022/04/09 17:41:37 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fract
{
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	max_iter;
	char	type;
	int		*gradg;
	int		*gradr;
	int		rog;
	int		mov;
}				t_fract;

typedef struct s_env
{
	void	*win;
	void	*mlx;
	t_data	data;
	t_fract	f;
}				t_base;

typedef struct s_dp
{
	double	x;
	double	y;
}				t_dp;

typedef struct s_ip
{
	int	x;
	int	y;
}				t_ip;

int		ft_strncmp(const char *s1, const char *s2);
void	init_grad(t_fract *f);
void	struct_init(t_fract *f, char *type);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_print(t_base *w, double iter, int i, int j);
void	m_print(t_base *w, int i, int j);
void	j_print(t_base *w, int i, int j, t_dp cord);
void	s_print(t_base *w, int i, int j);
void	ft_refresh(t_base *w);
int		ft_rendering(t_base *w);
int		e_exit(void);
int		lr_key(int btn, t_base *w);
int		ud_key(int btn, t_base *w);
int		ft_key_hook(int btn, t_base *w);
void	ft_scroll_down(int x, int y, t_fract *f);
void	ft_scroll_up(int x, int y, t_fract *f);
int		ft_mouse_hook(int btn, int x, int y, t_fract *f);
int		ft_loop_hook(t_base *w);
int		main(int argc, char **argv);

#endif
