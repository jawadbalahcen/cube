/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/03/21 16:57:40 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_err(void)
{
	printf("malloc fail\n");
	exit(1);
}

void	args_err(void)
{
	printf("invalid args\n");
	exit(1);
}

void	file_err(void)
{
	printf("cant open the scene description file\n");
	exit(1);
}

void	invalid_line_err(char *line, char *str)
{
	free(line);
	printf("misconfiguration : %s\n", str);
	exit(1);
}

void	error_exit(t_vars *vars, char *msg)
{
	end_game(vars);
	printf ("Error : %s\n", msg);
	exit(1);
}
