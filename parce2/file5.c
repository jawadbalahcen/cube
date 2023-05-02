/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:28:31 by jbalahce          #+#    #+#             */
/*   Updated: 2023/05/02 14:31:29 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_put_pixel_to_image(void *img_ptr, int x, int y, int color)
{
	int				size_line;
	int				bpp;
	int				endian;
	unsigned int	*data_ptr;
	int				pos;

	size_line = 0;
	bpp = 0;
	endian = 0;
	data_ptr = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line,
			&endian);
	if (x < 0 || y < 0 || y >= WIN_H || x >= WIN_W)
		return ;
	pos = (y * (size_line / 4) + x);
	data_ptr[pos] = color;
}

void	mini_map(t_vars *vars)
{
	t_grid_vars	gr_vrs;

	draw_grid(vars, &gr_vrs);
	draw_ray(vars, 15, vars->p.a, gr_vrs);
}
