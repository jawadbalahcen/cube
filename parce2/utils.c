/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/03/21 10:51:51 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_isstr_digit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (ft_isdigit(c[i]) == 1 || ft_isspace(c[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_isspace(char c)
{
	int	i;

	i = 0;
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	init_vars(t_vars *vars)
{
	vars->imgs.color_floor = -1;
	vars->imgs.color_celing = -1;
	vars->imgs.imge.img = NULL;
	vars->imgs.imgw.img = NULL;
	vars->imgs.imgs.img = NULL;
	vars->imgs.imgn.img = NULL;
}

void	ft_remove_char(char *c, int index)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(c);
	new = malloc(len - 1);
	i = 0;
	len = 0;
	while (new[i + len])
	{
		if (i == index)
			len++;
		else
		{
			new[i] = c[i + len];
			i++;
			len++;
		}
	}
	new[i] = 0;
	free(c);
	c = new;
}
