/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:12:19 by jbalahce          #+#    #+#             */
/*   Updated: 2023/05/01 14:17:00 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_side(t_inters ver_hor, t_vars *vars, t_dist_info dist_info)
{
	int	x;
	int	y;

	x = ver_hor.ax / GRID_SIZE;
	y = ver_hor.ay / GRID_SIZE;
	vars->wall.x_text = (int)ver_hor.ax % GRID_SIZE;
	if (dist_info.hor_or_ver == 0)
		vars->wall.x_text = (int)ver_hor.ay % GRID_SIZE;
	if (y < vars->p.p.y / GRID_SIZE && dist_info.hor_or_ver == 1)
	{
		vars->wall.texture = vars->imgs.imgn.img;
		// vars->wall.x_text = (int)ver_hor.ax % GRID_SIZE;
	}
	if (y > vars->p.p.y / GRID_SIZE && dist_info.hor_or_ver == 1)
	{
		vars->wall.texture = vars->imgs.imgs.img;
		// vars->wall.x_text = (int)ver_hor.ax % GRID_SIZE;
	}
	if (dist_info.hor_or_ver == 0 && x < vars->p.p.x / GRID_SIZE)
	{
		vars->wall.texture = vars->imgs.imgw.img;
	//	vars->wall.x_text = (int)ver_hor.ay % GRID_SIZE;
	}
	if (dist_info.hor_or_ver == 0 && x > vars->p.p.x / GRID_SIZE)
	{
		vars->wall.texture = vars->imgs.imge.img;
		// vars->wall.x_text = (int)ver_hor.ay % GRID_SIZE;
	}
	return (0);
}

void	find_wall(t_vars *vars, double ray)
{
	t_inters	horizontal;
	t_inters	vertical;
	t_dist_info	dist_info;

	horizontal = init_inters(-1, -1, -1, -1);
	vertical = init_inters(-1, -1, -1, -1);
	find_hor_wall(vars, &horizontal, ray);
	find_ver_wall(vars, &vertical, ray);
	dist_info = cal_wall_dist(vars, &horizontal, &vertical);
	!(dist_info.hor_or_ver) && wall_side(vertical, vars, dist_info);
	dist_info.hor_or_ver &&wall_side(horizontal, vars, dist_info);
	dist_info.distance *= cos(vars->p.a - ray);
	draw_colomn_v2(vars, dist_info);
}

int	move_player(int key, t_vars *vars)
{
	(key == ESC) && cross_mark();
	if (key == A_KEY)
		vars->state.angle = +M_PI_2;
	if (key == W_KEY)
		vars->state.angle = 0;
	if (key == D_KEY)
		vars->state.angle = -M_PI_2;
	if (key == S_KEY)
		vars->state.angle = +M_PI;
	if (key == RIGHT)
		vars->state.lookspeep = -1;
	if (key == LEFT)
		vars->state.lookspeep = 1;
	return (0);
}

int	release_btn(int key, t_vars *vars)
{
	if (key == A_KEY || key == W_KEY || key == D_KEY || key == S_KEY)
		vars->state.angle = DEF_ANGLE;
	else if (key == RIGHT || key == LEFT)
		vars->state.lookspeep = DEF_VIEW;
	return (key);
}

int	cross_mark(void)
{
	exit(0);
	return (0);
}
