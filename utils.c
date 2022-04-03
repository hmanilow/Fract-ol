#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void ft_gradientinit(t_fract *f)
{
//	fract->gradg = (int *)malloc(sizeof(int) * 6);
//	fract->gradr = (int *)malloc(sizeof(int) * 3);
//	fract->gradr[0] = 0xff0000;
//	fract->gradr[1] = 0xffffff;
//	fract->gradr[2] = 0x0000ff;
//	fract->gradg[0] = 0x800080;
//	fract->gradg[1] = 0xff0000;
//	fract->gradg[2] = 0xff8000;
//	fract->gradg[3] = 0xffff00;
//	fract->gradg[4] = 0x009900;
//	fract->gradg[5] = 0x0000bb;
	f->gradr = (int *)malloc(sizeof(int) * 3);
	f->gradg = (int *)malloc(sizeof(int) * 6);
	f->gradr[0] = 0xff0000;
	f->gradr[1] = 0xffffff;
	f->gradr[2] = 0x0000ff;
	f->gradg[0] = 0x800080;
	f->gradg[1] = 0xff0000;
	f->gradg[2] = 0xff8000;
	f->gradg[3] = 0xffff00;
	f->gradg[4] = 0x009900;
	f->gradg[5] = 0x0000bb;
}
