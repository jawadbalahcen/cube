#include "cub3d.h"

void	draw_sqr(t_vars *vars, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = y;
	while ((i - y) < size - 1)
	{
		j = x;
		while ((j - x) < size - 1)
		{
			my_put_pixel_to_image(vars->img_ptr, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_grid(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 25)
		{
			if (vars->map[i][j] == '1')
				draw_sqr(vars, j * 64, i * 64, RED, 64);
			else
				draw_sqr(vars, j * 64, i * 64, BLUE, 64);
			if (vars->map[i][j] == 'N')
				draw_sqr(vars, vars->p.p.x, vars->p.p.y, PINK, 5);
			j++;
		}
		i++;
	}
}
void	draw_ray(t_vars *vars, double distance, double ray)
{
	int		i;
	double	offset_x;
	double	offset_y;
	double	x;
	double	y;

	i = 0;
	offset_x = cos(-ray);
	offset_y = sin(-ray);
	x = vars->p.p.x;
	y = vars->p.p.y;
	while (i < distance)
	{
		my_put_pixel_to_image(vars->img_ptr, x, y, vars->imgs.color_celing);
		x += offset_x;
		y += offset_y;
		i++;
	}
}
void	put_string(t_vars *vars)
{
	int i = 0;
	int j = 0;
	char *str;
	while (i * 64 < WIN_H)
	{
		j = 0;
		while (j * 64 < WIN_W)
		{
			str = ft_strjoin(ft_itoa(j), ",");
			str = ft_strjoin(str, ft_itoa(i));
			mlx_string_put(vars->mlx, vars->win, (j * 64) + 5, (i * 64) + 5,
					BLACK, str);
			j++;
		}
		i++;
	}
}