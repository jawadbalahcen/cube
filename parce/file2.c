/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:30:42 by jbalahce          #+#    #+#             */
/*   Updated: 2023/04/26 15:23:15 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	correct_angle(double *angle)
{
	if (*angle < 0)
		*angle = *angle + (2 * M_PI);
	if (*angle >= (2 * M_PI))
		*angle = *angle - (2 * M_PI);
}

void	check_ver_inters1(t_vars *vars, t_inters *vertical, double ray)
{
	if (ray == M_PI)
		*vertical = init_inters(((vars->p.p.x / GRID_SIZE) * GRID_SIZE) - 0.0001,
								vars->p.p.y,
								-(GRID_SIZE),
								0);
	if (M_PI < ray && ray < (3 * M_PI) / 2)
	{
		vertical->ax = ((vars->p.p.x / GRID_SIZE) * GRID_SIZE) - 0.0001;
		*vertical = init_inters(vertical->ax, vars->p.p.y + ((vars->p.p.x
						- vertical->ax) * tan(ray - M_PI)), -GRID_SIZE,
				GRID_SIZE * tan(ray - M_PI));
	}
	if (ray == (3 * M_PI) / 2)
		return ;
	if ((3 * M_PI) / 2 < ray && ray < (2 * M_PI))
	{
		vertical->ax = ((vars->p.p.x / GRID_SIZE) * GRID_SIZE) + GRID_SIZE;
		*vertical = init_inters(vertical->ax, vars->p.p.y + ((vertical->ax
						- vars->p.p.x) * tan((2 * M_PI) - ray)), GRID_SIZE,
				GRID_SIZE * tan((2 * M_PI) - ray));
	}
}

void	check_ver_inters(t_vars *vars, t_inters *vertical, double ray)
{
	if (ray == 0)
		*vertical = init_inters(((vars->p.p.x / GRID_SIZE) * GRID_SIZE)
				+ GRID_SIZE,
								vars->p.p.y,
								GRID_SIZE,
								0);
	if (0 < ray && ray < (M_PI / 2))
	{
		vertical->ax = ((vars->p.p.x / GRID_SIZE) * GRID_SIZE) + GRID_SIZE;
		*vertical = init_inters(vertical->ax,
								vars->p.p.y - ((vertical->ax - vars->p.p.x)
										* tan(ray)),
								GRID_SIZE,
								-(GRID_SIZE * tan(ray)));
	}
	if (ray == M_PI_2)
		return ;
	if (M_PI_2 < ray && ray < M_PI)
	{
		vertical->ax = ((vars->p.p.x / GRID_SIZE) * GRID_SIZE) - 0.0001;
		*vertical = init_inters(vertical->ax, vars->p.p.y - ((vars->p.p.x
						- vertical->ax) * tan(M_PI - ray)), -GRID_SIZE,
				-(GRID_SIZE * tan(M_PI - ray)));
	}
	check_ver_inters1(vars, vertical, ray);
}

void	find_hor_wall(t_vars *vars, t_inters *horizontal, double ray)
{
	check_hor_inters(vars, horizontal, ray);
	if (horizontal->ax < 0 || horizontal->ay < 0)
		return ;
	while (horizontal->ax != -1 && (size_t)(horizontal->ax)
		/ GRID_SIZE < ft_strlen((vars->map)[(int)(horizontal->ay / GRID_SIZE)]))
	{
		if ((vars->map)[(int)(horizontal->ay / GRID_SIZE)][(int)(horizontal->ax
			/ GRID_SIZE)] == '1')
			break ;
		horizontal->ax += horizontal->offset_x;
		horizontal->ay += horizontal->offset_y;
	}
}

void	find_ver_wall(t_vars *vars, t_inters *vertical, double ray)
{
	check_ver_inters(vars, vertical, ray);
	if (vertical->ax < 0 || vertical->ay < 0)
		return ;
	while (vertical->ax != -1 && (int)vertical->ay / GRID_SIZE < vars->size_map
		&& (int)vertical->ay / GRID_SIZE >= 0 && (size_t)(vertical->ax
		/ GRID_SIZE) < ft_strlen((vars->map)[(int)(vertical->ay / GRID_SIZE)]))
	{
		if ((vars->map)[(int)(vertical->ay / GRID_SIZE)][(int)(vertical->ax
				/ GRID_SIZE)] == '1')
			break ;
		vertical->ax += vertical->offset_x;
		vertical->ay += vertical->offset_y;
	}
}
