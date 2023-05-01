/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/05/01 14:44:57 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_buffer(char **buffer, int fd)
{
	char	*new;
	char	*old;

	while (1)
	{
		new = get_next_line(fd);
		if (new == NULL)
			break ;
		old = *buffer;
		*buffer = ft_strjoin(old, new);
		free(old);
		free(new);
	}
}

void	end_game(t_vars *vars)
{
	ft_free_split(vars->map);
	mlx_destroy_image(vars->mlx, vars->imgs.imge.img);
	mlx_destroy_image(vars->mlx, vars->imgs.imgw.img);
	mlx_destroy_image(vars->mlx, vars->imgs.imgn.img);
	mlx_destroy_image(vars->mlx, vars->imgs.imgs.img);
}

int	is_char_valid(char c)
{
	char	s[7];
	int		i;

	s[0] = '0';
	s[1] = '1';
	s[2] = 'N';
	s[3] = 'E';
	s[4] = 'W';
	s[5] = 'S';
	s[6] = 0;
	i = 0;
	if (ft_isspace(c) == 1)
		return (1);
	while (i <= 6)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_chars(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (is_char_valid(vars->map[i][j]) == 0)
				error_exit(vars, "invalid characters in map");
			j++;
		}
		i++;
	}
	return (1);
}

void	change_spaces(t_vars *vars)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			// if (ft_isspace(vars->map[i][j]) == 1)  // removed 1 instead of space
			// 	vars->map[i][j] = '1';
			if (ft_isalpha(vars->map[i][j]) == 1)
				p++;
			if (p == 2)
				error_exit(vars, "map should only 1 spawning point");
			j++;
		}
		i++;
	}
}

int	ft_isblock(char c)
{
	if (c == '1')
		return (1);
	if (ft_isspace(c) == 1)
		return (1);
	return (0);
}

void	check_first_line(t_vars *vars)
{
	int	i;

	if (vars->map[1] == NULL)
		error_exit(vars, "invalid map");
	i = 0;
	while (vars->map[0][i])
	{
		if (ft_isblock(vars->map[0][i]) == 0)
			error_exit(vars, "map must be surronded by walls");
		i++;
	}
}

void	check_last_line(t_vars *vars, int index)
{
	int	i;

	i = 0;
	while (vars->map[index][i])
	{
		if (ft_isblock(vars->map[index][i]) == 0)
			error_exit(vars, "map must be surronded by walls");
		if (vars->map[index][i] == '\n')
			error_exit(vars, "map cant have emppty lines");
		i++;
	}
}

void	check_top_below(t_vars *vars, int i, int j)
{
	if ((int)ft_strlen(vars->map[i - 1]) < j + 1)
		error_exit(vars, "map must be surronded by walls \
			(spaces are considered empty gaps or void)");
	if ((int)ft_isspace(vars->map[i - 1][j]) == 1)
		error_exit(vars, "map must be surronded by walls \
			(spaces are considered empty gaps or void)");
	if ((int)ft_strlen(vars->map[i + 1]) < j + 1)
		error_exit(vars, "map must be surronded by walls \
			(spaces are considered empty gaps or void)");
	if ((int)ft_isspace(vars->map[i + 1][j]) == 1)
		error_exit(vars, "map must be surronded by walls \
			(spaces are considered empty gaps or void)");
}

void	check_line(t_vars *vars, int index)
{
	int	i;

	i = 1;
	while (vars->map[index][i])
	{
		if (i == 0 && ft_isblock(vars->map[index][i]) == 0)
			error_exit(vars, "map must be surronded by walls");
		else if (ft_isblock(vars->map[index][i]) == 0)
		{
			if (ft_isspace(vars->map[index][i - 1]) == 1)
				error_exit(vars, "map must be surronded by walls \
					(spaces are considered empty gaps or void)");
			if (ft_isspace(vars->map[index][i + 1]) == 1
				|| (vars->map[index][i + 1] == 0))
				error_exit(vars, "map must be surronded by walls \
					(spaces are considered empty gaps or void)");
			check_top_below(vars, index ,i);
		}
		i++;
	}

}

void	check_closed(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (i == 0)
			check_first_line(vars);
		else if (vars->map[i + 1] == NULL)
			check_last_line(vars, i);
		else
			check_line(vars, i);
		i++;
	}
}

void	handle_map(t_vars *vars, int fd)
{
	char	*buffer;

	buffer = NULL;
	fill_buffer(&buffer, fd);
	close(fd);
	vars->map = ft_split(buffer, '\n');
	free(buffer);
	if (vars->map == NULL)
		malloc_err();
	check_chars(vars);
	check_closed(vars);
	change_spaces(vars);
	return;
}
