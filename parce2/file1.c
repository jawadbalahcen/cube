/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:35:47 by jbalahce          #+#    #+#             */
/*   Updated: 2023/05/02 14:04:52 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pos(t_cords *cords, char **map, char c)
{
	cords->y = 0;
	while (map[cords->y])
	{
		cords->x = 0;
		while (map[cords->y][cords->x])
		{
			if (map[cords->y][cords->x] == c)
				return ;
			(cords->x)++;
		}
		(cords->y)++;
	}
	cords->y = -1;
	cords->x = -1;
}

void	init_player(t_vars *vars)
{
	char	*set;

	vars->state.angle = DEF_ANGLE;
	vars->state.lookspeep = DEF_VIEW;
	set = "NESW";
	while (*set)
	{
		get_pos(&(vars->p.p), vars->map, *set);
		if (vars->p.p.x != -1)
			break ;
		set++;
	}
	(*set == 'N') && (vars->p.a = M_PI_2);
	(*set == 'E') && (vars->p.a = 0);
	(*set == 'S') && (vars->p.a = (3 * M_PI) / 2);
	(*set == 'W') && (vars->p.a = M_PI);
	vars->p.p.x = (vars->p.p.x * GRID_SIZE) + (GRID_SIZE / 2);
	vars->p.p.y = (vars->p.p.y * GRID_SIZE) + (GRID_SIZE / 2);
}

t_inters	init_inters(double ax, double ay, double offset_x, double offset_y)
{
	t_inters	test;

	test.ax = ax;
	test.ay = ay;
	test.offset_x = offset_x;
	test.offset_y = offset_y;
	return (test);
}

void	check_hor_inters1(t_vars *vars, t_inters *horizontal, double ray)
{
	if (M_PI < ray && ray < (3 * M_PI) / 2)
	{
		horizontal->ay = ((vars->p.p.y / GRID_SIZE) * GRID_SIZE) + GRID_SIZE;
		*horizontal = init_inters(vars->p.p.x - ((horizontal->ay - vars->p.p.y)
					/ tan(ray - M_PI)), horizontal->ay, -(GRID_SIZE / tan(ray
						- M_PI)), GRID_SIZE);
	}
	if (ray == (3 * M_PI) / 2)
		*horizontal = init_inters(vars->p.p.x, ((vars->p.p.y / GRID_SIZE)
					* GRID_SIZE) + GRID_SIZE, 0, GRID_SIZE);
	if ((3 * M_PI) / 2 < ray && ray < (2 * M_PI))
	{
		horizontal->ay = ((vars->p.p.y / GRID_SIZE) * GRID_SIZE) + GRID_SIZE;
		*horizontal = init_inters(vars->p.p.x
				+ ((horizontal->ay - vars->p.p.y) / tan((2 * M_PI) - ray)),
				horizontal->ay,
				GRID_SIZE / tan((2 * M_PI) - ray),
				GRID_SIZE);
	}
}

void	check_hor_inters(t_vars *vars, t_inters *horizontal, double ray)
{
	if (ray == 0)
		return ;
	if (0 < ray && ray < M_PI_2)
	{
		horizontal->ay = ((vars->p.p.y / GRID_SIZE) * GRID_SIZE) - 0.0001;
		*horizontal = init_inters(vars->p.p.x + ((vars->p.p.y - horizontal->ay)
					/ tan(ray)), horizontal->ay, GRID_SIZE / tan(ray),
				-GRID_SIZE);
	}
	if (ray == M_PI_2)
		*horizontal = init_inters(vars->p.p.x, ((vars->p.p.y / GRID_SIZE)
					* GRID_SIZE) - 1, 0, -GRID_SIZE);
	if (M_PI_2 < ray && ray < M_PI)
	{
		horizontal->ay = ((vars->p.p.y / GRID_SIZE) * GRID_SIZE) - 0.0001;
		*horizontal = init_inters(vars->p.p.x - ((vars->p.p.y - horizontal->ay)
					/ tan(M_PI - ray)), horizontal->ay, -(GRID_SIZE / tan(M_PI
						- ray)), -GRID_SIZE);
	}
	if (ray == M_PI)
		return ;
	check_hor_inters1(vars, horizontal, ray);
}
