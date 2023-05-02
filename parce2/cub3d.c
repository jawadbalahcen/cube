/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/05/02 15:03:17 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	la_function(t_vars *vars)
{
	int		x;
	int		y;
	double	offset_x;
	double	offset_y;
	char	map_value;

	if (vars->state.lookspeep != DEF_VIEW)
		vars->p.a += vars->state.lookspeep * LOOK_SPEED * 2;
	if (vars->state.angle != DEF_ANGLE)
	{
		offset_x = cos(-(vars->state.angle + vars->p.a));
		offset_y = sin(-(vars->state.angle + vars->p.a));
		x = vars->p.p.x + (int)(offset_x * MOVE_SPEED);
		y = vars->p.p.y + (int)(offset_y * MOVE_SPEED);
		map_value = vars->map[vars->p.p.y / GRID_SIZE][(int)(x + (offset_x * 8))
			/ GRID_SIZE];
		if (map_value != '1')
			vars->p.p.x = x;
		map_value = vars->map[(int)(y + (offset_y * 8)) / GRID_SIZE][vars->p.p.x
			/ GRID_SIZE];
		if (map_value != '1')
			vars->p.p.y = y;
	}
	cast_rays(vars);
	return (1);
}

int	mouse(int x, int y, t_vars *vars)
{
	int	dist;
	int	condition;

	mlx_mouse_show();
	if (y < 0 || y > WIN_H || x < 0 || x > WIN_W)
	{
		condition = ((y >= 0) && (y <= WIN_H));
		(x < 0) && condition && mlx_mouse_move(vars->win, WIN_W, y);
		(x > WIN_W) && condition && mlx_mouse_move(vars->win, 0, y);
		vars->mouse_pos.x = 0;
		return (0);
	}
	if (vars->mouse_pos.x)
	{
		mlx_mouse_hide();
		dist = (vars->mouse_pos.x - x);
		vars->p.a += dist * (LOOK_SPEED / 10);
		correct_angle(&vars->p.a);
	}
	vars->mouse_pos.x = x;
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_vars	vars;

	if (argc != 2)
		args_err();
	vars.p.a = 0;
	vars.img_ptr = NULL;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "CUB");
	validation(&vars, (char **)argv);
	init_player(&vars);
	cast_rays(&vars);
	vars.mouse_pos.x = 0;
	mlx_hook(vars.win, 2, 0, move_player, &vars);
	mlx_hook(vars.win, 3, 0, release_btn, &vars);
	mlx_hook(vars.win, 6, 0, mouse, &vars);
	mlx_hook(vars.win, 17, 0, cross_mark, NULL);
	mlx_loop_hook(vars.mlx, la_function, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
