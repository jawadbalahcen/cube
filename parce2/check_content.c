/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/05/02 14:48:44 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_val(char *line, void *to_set, int name)
{
	int	i;

	if (ft_isspace(line[name + 1]) == 0)
		invalid_line_err(line, "unknown rule");
	i = name + 1;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 1 && name == 1)
			invalid_line_err(line, "invalid value");
		if (line[i] == '\\')
		{
			ft_remove_char(line, i);
			if (line[i] == 0)
				i--;
		}
		i++;
	}
	if (name == 0)
		get_rgbval(line, to_set);
	else
		get_imgpath(line, to_set);
}

void	get_attr(char *line, t_vars *vars)
{
	if (ft_strlen(line) == 0)
		return ;
	if (line[0] == '0' || line[0] == '1')
		invalid_line_err(line, "invalide rules");
	if (line[0] == 'F')
		setup_val(line, &vars->imgs.color_floor, 0);
	else if (line[0] == 'C')
		setup_val(line, &vars->imgs.color_celing, 0);
	else if (line[0] == 'N' && line[1] == 'O')
		setup_val(line, vars, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		setup_val(line, vars, 1);
	else if (line[0] == 'W' && line[1] == 'E')
		setup_val(line, vars, 1);
	else if (line[0] == 'E' && line[1] == 'A')
		setup_val(line, vars, 1);
	else
		invalid_line_err(line, "unknown rule!");
}

int	check_order(t_vars *vars)
{
	if (vars->imgs.imge.img == NULL)
		return (1);
	if (vars->imgs.imgw.img == NULL)
		return (1);
	if (vars->imgs.imgs.img == NULL)
		return (1);
	if (vars->imgs.imgn.img == NULL)
		return (1);
	if (vars->imgs.color_floor == -1)
		return (1);
	if (vars->imgs.color_celing == -1)
		return (1);
	return (0);
}

char	*get_line(int *fd)
{
	char	*line;
	char	*line2;

	line = get_next_line(*fd);
	if (line == NULL)
	{
		close(*fd);
		*fd = -1;
		return (line);
	}
	line2 = ft_strtrim(line, "\t\n\v\f\r ");
	free(line);
	return (line2);
}

void	get_elements(t_vars *vars, int fd)
{
	char	*line;

	init_vars(vars);
	while (1)
	{
		if (check_order(vars) == 1)
			line = get_line(&fd);
		else
		{
			handle_map(vars, fd);
			return ;
		}
		if (fd == -1 || line == NULL)
			return ;
		if (*line == 0 || *line == '\n')
			free(line);
		else
		{
			get_attr(line, vars);
			free(line);
		}
	}
}
