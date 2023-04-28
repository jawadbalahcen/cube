/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:12:19 by jbalahce          #+#    #+#             */
/*   Updated: 2023/04/28 12:05:38 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_side(t_inters ver_hor, t_vars *vars, t_dist_info dist_info)
{
	int	x;
	int	y;

	x = ver_hor.ax / GRID_SIZE;
	y = ver_hor.ay / GRID_SIZE;
	if (y < vars->p.p.y / GRID_SIZE && dist_info.hor_or_ver == 1)
		vars->wall_color = NO_RED;
	if (y > vars->p.p.y / GRID_SIZE && dist_info.hor_or_ver == 1)
		vars->wall_color = SO_BLUE;
	if (dist_info.hor_or_ver == 0 && x < vars->p.p.x / GRID_SIZE)
		vars->wall_color = WE_YELLOW;
	if (dist_info.hor_or_ver == 0 && x > vars->p.p.x / GRID_SIZE)
		vars->wall_color = EA_GREEN;
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
	draw_colomn(vars, dist_info);
}
/*
int	change_view(int key, t_vars *vars)
{
	if (key == RIGHT)
	{
		vars->p.a -= LOOK_SPEED;
		// cast_rays(vars);
	}
	if (key == LEFT)
	{
		vars->p.a += LOOK_SPEED;
		// cast_rays(vars);
	}
	return (0);
}
*/

int	handle_key(t_vars *vars, double offset_angle)
{
	int		i;
	int		x;
	int		y;
	double	offset_x;
	double	offset_y;

	//printf("%f",offset_angle);
	if (offset_angle < 0)
	{
		cast_rays(vars);
		return 0;
	}
	i = 0;
	offset_x = cos(-offset_angle);
	offset_y = sin(-offset_angle);
	x = vars->p.p.x + (int)(offset_x * MOVE_SPEED);
	y = vars->p.p.y + (int)(offset_y * MOVE_SPEED);
	if ((vars->map[y / GRID_SIZE][x / GRID_SIZE] != '1'))
	{
		while (i < MOVE_SPEED)
		{
			vars->p.p.x += offset_x;
			vars->p.p.y += offset_y;
			cast_rays(vars);
			i++;
		}
		vars->p.p.x = x;
		vars->p.p.y = y;
		cast_rays(vars);
	}
	return (0);
}
/*
int	move_player(int key, t_vars *vars)
{
	printf("%i\n",key);
	(key == ESC) && cross_mark();
	(key == A_KEY) && handle_key(vars, vars->p.a + M_PI_2);
	(key == W_KEY) && handle_key(vars, vars->p.a);
	(key == D_KEY) && handle_key(vars, vars->p.a - M_PI_2);
	(key == S_KEY) && handle_key(vars, vars->p.a + M_PI);
	if (key == RIGHT)
	{
		vars->p.a -= LOOK_SPEED;
	}
	if (key == LEFT)
	{
		vars->p.a += LOOK_SPEED;
		// cast_rays(vars);
	}
	return (0);
}*/

int	move_player(int key, t_vars *vars)
{
	//printf("%i\n",key);
	(key == ESC) && cross_mark();
	if (key == A_KEY) vars->state.angle = vars->p.a + M_PI_2;
	if (key == W_KEY) vars->state.angle = vars->p.a;
	if (key == D_KEY) vars->state.angle = vars->p.a - M_PI_2;
	if (key == S_KEY) vars->state.angle = vars->p.a + M_PI;
	if (key == RIGHT) vars->state.lookspeep = -1;
	if (key == LEFT) vars->state.lookspeep = 1;
	return (0);
}

int	release_btn(int key, t_vars *vars)
{
	//printf("%iresles\n",key);
	if (key == A_KEY || key == W_KEY
		|| key == D_KEY || key == S_KEY)
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
