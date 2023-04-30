/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/04/30 17:25:25 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	get_attr(char *line, t_vars *vars)
{
	if (ft_strlen(line) < 2)
		invalid_line_err(line);
	if (line[0] == 'F' && ft_isspace(line[1]) == 1)
	if (line[0] == 'C' && ft_isspace(line[1]) == 1)
	if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]) == 1)
	if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]) == 1)
	if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]) == 1)
	if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]) == 1)
}
*/

void	paricing_test(t_vars *vars)
{
	int	i;
	int	j;

	printf("img N = %p | h = %i, w = %i\n", vars->imgs.imgn.img,
			vars->imgs.imgn.h, vars->imgs.imgn.w);
	printf("img E = %p | h = %i, w = %i\n", vars->imgs.imge.img,
			vars->imgs.imge.h, vars->imgs.imge.w);
	printf("img W = %p | h = %i, w = %i\n", vars->imgs.imgw.img,
			vars->imgs.imgw.h, vars->imgs.imgn.w);
	printf("img S = %p | h = %i, w = %i\n", vars->imgs.imgs.img,
			vars->imgs.imgs.h, vars->imgs.imgs.w);
	printf("floor color value = %i\n", vars->imgs.color_floor);
	printf("celing color value = %i\n", vars->imgs.color_celing);
	printf("maps :\n");
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			printf("%c", vars->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	la_function(t_vars *vars)
{
	int		x;
	int		y;
	double	offset_x;
	double	offset_y;

	if (vars->state.lookspeep != DEF_VIEW)
		vars->p.a += vars->state.lookspeep * LOOK_SPEED * 2;
	if (vars->state.angle != DEF_ANGLE)
	{
		offset_x = cos(-(vars->state.angle + vars->p.a));
		offset_y = sin(-(vars->state.angle + vars->p.a));
		x = vars->p.p.x + (int)(offset_x * MOVE_SPEED);
		y = vars->p.p.y + (int)(offset_y * MOVE_SPEED);
		if ((vars->map[vars->p.p.y / GRID_SIZE][(int)(x + (offset_x * 8))
				/ GRID_SIZE] != '1') && (vars->map[vars->p.p.y / GRID_SIZE][(int)(x + (offset_x * 8))
				/ GRID_SIZE] != 'D'))
			vars->p.p.x = x;
		if ((vars->map[(int)(y + (offset_y * 8)) / GRID_SIZE][vars->p.p.x
				/ GRID_SIZE] != '1') && (vars->map[(int)(y + (offset_y * 8)) / GRID_SIZE][vars->p.p.x
				/ GRID_SIZE] != 'D'))
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
		condition = (y >= 0) && (y <= WIN_H);
		(x < 0) && condition &&mlx_mouse_move(vars->win, WIN_W, y);
		(x > WIN_W) && condition &&mlx_mouse_move(vars->win, 0, y);
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
