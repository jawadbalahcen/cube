/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/05/02 14:51:54 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_save_img(char *line, void *to_set, t_vars *vars, int i)
{
	t_img	*img;
	int		h;
	int		w;

	img = (t_img *)to_set;
	if (img->img != NULL)
		invalid_line_err(line, "dupkicit rule");
	img->img = mlx_xpm_file_to_image(vars->mlx, line + i, &w, &h);
	if (img->img == NULL)
		invalid_line_err(line, "invalid img");
	img->h = h;
	img->w = w;
}

void	get_imgpath(char *line, void *to_set)
{
	int		i;
	t_vars	*vars;

	vars = (t_vars *)to_set;
	i = 2;
	if (ft_isspace(line[i]) == 0)
		invalid_line_err(line, "unknown rule");
	while (ft_isspace(line[i]))
		i++;
	if (line[0] == 'N' && line[1] == 'O')
		ft_save_img(line, &vars->imgs.imgn, vars, i);
	if (line[0] == 'S' && line[1] == 'O')
		ft_save_img(line, &vars->imgs.imgs, vars, i);
	if (line[0] == 'W' && line[1] == 'E')
		ft_save_img(line, &vars->imgs.imgw, vars, i);
	if (line[0] == 'E' && line[1] == 'A')
		ft_save_img(line, &vars->imgs.imge, vars, i);
}
