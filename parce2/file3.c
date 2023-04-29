/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:42:23 by jbalahce          #+#    #+#             */
/*   Updated: 2023/04/29 15:58:36 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dist_info	cal_wall_dist(t_vars *vars, t_inters *horizontal,
		t_inters *vertical)
{
	t_dist_info	hor_dis;
	t_dist_info	ver_dis;

	hor_dis.distance = -1;
	ver_dis.distance = -1;
	hor_dis.hor_or_ver = 1;
	ver_dis.hor_or_ver = 0;
	if (horizontal->ax >= 0 && horizontal->ay >= 0)
		hor_dis.distance = sqrt(pow(vars->p.p.x - horizontal->ax, 2)
				+ pow(vars->p.p.y - horizontal->ay, 2));
	if (vertical->ax >= 0 && vertical->ay >= 0)
		ver_dis.distance = sqrt(pow(vars->p.p.x - vertical->ax, 2)
				+ pow(vars->p.p.y - vertical->ay, 2));
	if (hor_dis.distance < 0)
		return (ver_dis);
	if (ver_dis.distance < 0)
		return (hor_dis);
	if ((hor_dis.distance >= ver_dis.distance))
		return (ver_dis);
	return (hor_dis);
}

void	my_put_pixel_to_image(void *img_ptr, int x, int y, int color)
{
	int				size_line;
	int				bpp;
	int				endian;
	unsigned int	*data_ptr;
	int				pos;

	size_line = 0;
	bpp = 0;
	endian = 0;
	data_ptr = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line,
			&endian);
	if (x < 0 || y < 0 || y >= WIN_H || x >= WIN_W)
		return ;
	pos = (y * (size_line / 4) + x);
	data_ptr[pos] = color;
}

void	draw_flr_ceil(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				my_put_pixel_to_image(vars->img_ptr, x, y,
						vars->imgs.color_celing);
			else
				my_put_pixel_to_image(vars->img_ptr, x, y,
						vars->imgs.color_floor);
			x++;
		}
		y++;
	}
}

void	draw_colomn(t_vars *vars, t_dist_info dist_info)
{
	double	virt_hight;
	int		end;
	int		start;

	virt_hight = ((double)(GRID_SIZE) / dist_info.distance) * SCALE;
	start = ((double)WIN_H / 2) - (virt_hight / 2);
	end = ((double)WIN_H / 2) + (virt_hight / 2);
	while (start <= end)
	{
		my_put_pixel_to_image(vars->img_ptr, vars->i, start, vars->wall_color);
		my_put_pixel_to_image(vars->img_ptr, vars->i - 1, start,
				vars->wall_color);
		start++;
	}
}

void	my_put_pixel_to_image_v2(void *img_ptr, int x, int y, t_wall wall)
{
	int				size_line;
	int				bpp;
	int				endian;
	unsigned int	*data_ptr;
	unsigned int	*data_ptr_text;
	int				pos;
	int				pos_text;

	size_line = 0;
	bpp = 0;
	endian = 0;
	data_ptr = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line,
			&endian);
	pos = (y * (size_line / 4) + x);
	data_ptr_text = (unsigned int *)mlx_get_data_addr(wall.texture, &bpp,
			&size_line, &endian);
	if (x < 0 || y < 0 || y >= WIN_H || x >= WIN_W)
		return ;
	if (wall.x_text < 0 || wall.y_text < 0 || wall.y_text >= GRID_SIZE * 5
		|| wall.x_text >= GRID_SIZE)
		return ;
	pos_text = (wall.y_text * (size_line / 4) + wall.x_text);
	data_ptr[pos] = data_ptr_text[pos_text];
}

void	draw_colomn_v2(t_vars *vars, t_dist_info dist_info)
{
	double	virt_hight;
	double	end;
	double	start;
	double	repeat_pixel;
	double	i;
	double	j;

	i = 0;
	virt_hight = ((double)(GRID_SIZE) / dist_info.distance) * SCALE;
	repeat_pixel = (virt_hight) / (GRID_SIZE);
	j = 1 / (repeat_pixel);
	start = ((double)WIN_H / 2) - (virt_hight / 2);
	end = ((double)WIN_H / 2) + (virt_hight / 2);
	vars->wall.y_text = 0;
	while (start <= end)
	{
		my_put_pixel_to_image_v2(vars->img_ptr, vars->i, start, vars->wall);
		my_put_pixel_to_image_v2(vars->img_ptr, vars->i - 1, start, vars->wall);
		start++;
		i += j * 5;
		(vars->wall.y_text) = i;
	}
}

int	cast_rays(t_vars *vars)
{
	double	start_view;
	double	end_view;
	double	ray;

	vars->i = WIN_W;
	mlx_clear_window(vars->mlx, vars->win);
	correct_angle(&vars->p.a);
	vars->img_ptr &&mlx_destroy_image(vars->mlx, vars->img_ptr);
	vars->img_ptr = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	draw_flr_ceil(vars);
	start_view = vars->p.a - (FOV / 2);
	end_view = vars->p.a + (FOV / 2);
	while (start_view <= end_view)
	{
		ray = start_view;
		correct_angle(&ray);
		find_wall(vars, ray);
		start_view += ANG_BTW_RAY;
		(vars->i) -= 2;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ptr, 0, 0);
	return (0);
}
