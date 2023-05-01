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
	int		i;
	int		j;
	double	x;
	double	y;

	x = ((vars->p.p.x - (GRID_SIZE / 2)) / (double)GRID_SIZE);
	y = ((vars->p.p.y - (GRID_SIZE / 2)) / (double)GRID_SIZE);
	i = y - 5;
	j = x - 5;
	while (i < vars->size_map && i < y + 5)
	{
		while (i < 0)
			i++;
		j = x - 5;
		while (j < (int)ft_strlen(vars->map[i]) && j < x + 5)
		{
			while (j < 0)
				j++;
			if (vars->map[i][j] == '1')
				draw_sqr(vars, j * 15, i * 15, RED, 15);
			else if (vars->map[i][j] != ' ')
				draw_sqr(vars, j * 15, i * 15, BLUE, 15);
			j++;
		}
		i++;
	}
	draw_sqr(vars, (x * 15) + 5, (y * 15) + 5, GREEN, 6);
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
	x = (((vars->p.p.x - (GRID_SIZE / 2)) / (double)GRID_SIZE) * 15) + 7;
	y = (((vars->p.p.y - (GRID_SIZE / 2)) / (double)GRID_SIZE) * 15) + 7;
	while (i < distance)
	{
		my_put_pixel_to_image(vars->img_ptr, x, y, PINK);
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
					GREEN, str);
			j++;
		}
		i++;
	}
}