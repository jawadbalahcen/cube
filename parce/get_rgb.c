/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/03/21 20:41:43 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_rgb(char *str, char **split)
{
	char	hex_val[7];
	int		i;
	int		val;

	i = 0;
	while (split[i])
	{
		val = ft_atoi(split[i]);
		if (val >= 0 && val <= 255)
		{
			hex_val[i * 2 + 1] = dig_to_hex(val % 16);
			hex_val[i * 2] = dig_to_hex((val - (val % 16)) / 16);
		}
		else
		{
			ft_free_split(split);
			invalid_line_err(str, "invalid RGB value");
		}
		i++;
	}
	hex_val[6] = 0;
	return (hex_to_int(hex_val));
}

int	check_spit_content(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (-1);
	i = 0;
	while (split[i])
	{
		if (ft_isstr_digit(split[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	get_rgbval(char *line, void *to_set)
{
	int		i;
	char	**split;

	i = 1;
	if (ft_isspace(line[i]) == 0)
		invalid_line_err(line, "unknown rule");
	while (ft_isspace(line[i]))
		i++;
	split = ft_split(line + i, ',');
	if (check_spit_content(split) != 0)
	{
		ft_free_split(split);
		invalid_line_err(line, "invalid RGB value!");
	}
	if (*(int *)to_set != -1)
	{
		ft_free_split(split);
		invalid_line_err(line, "duplicit rule");
	}
	*(int *)to_set = ft_atoi_rgb(line, split);
	ft_free_split(split);
}
