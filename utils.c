/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:41:55 by hmanilow          #+#    #+#             */
/*   Updated: 2022/04/09 17:41:57 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	init_grad(t_fract *f)
{
	f->gradr = (int *)malloc(sizeof(int) * 3);
	f->gradg = (int *)malloc(sizeof(int) * 6);
	if (!f->gradr || !f->gradg)
		exit(0);
	f->gradr[0] = 0x00ffff;
	f->gradr[1] = 0x0080ff;
	f->gradr[2] = 0x00ff80;
	f->gradg[0] = 0xff0080;
	f->gradg[1] = 0xff8000;
	f->gradg[2] = 0xff8000;
	f->gradg[3] = 0x0000ff;
	f->gradg[4] = 0x00ff00;
	f->gradg[5] = 0xfebfbf;
}
