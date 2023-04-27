/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/04/27 09:01:52 by jbalahce         ###   ########.fr       */
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

int	f(int x, int y, t_vars *vars)
{
	(void)vars;
	printf("x : [%d] y : [%d]\n", x, y);
	mlx_pixel_put(vars->mlx, vars->win, x, y, SO_BLUE);
	return (0);
}

int	movehh(int key, t_vars *vars)
{
	(void) vars;
	printf("%i relese \n",key);return (0);
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
	paricing_test(&vars);
	mlx_hook(vars.win, 2, 0, move_player, &vars);
	mlx_hook(vars.win, 3, 0, movehh, &vars);
	mlx_hook(vars.win, 17, 0, cross_mark, NULL);
	mlx_loop_hook(vars.mlx, cast_rays, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
