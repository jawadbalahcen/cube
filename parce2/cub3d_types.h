/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:20:32 by jbalahce          #+#    #+#             */
/*   Updated: 2023/05/01 14:44:09 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPES_H
# define CUB3D_TYPES_H

# define A_KEY 0
# define W_KEY 13
# define D_KEY 2
# define S_KEY 1

# define RIGHT 124
# define LEFT 123
# define ESC 53

# define DEF_ANGLE -1
# define DEF_VIEW 0

# define TEXT_SCALE 10

# define RED 0xFF3333
# define BLUE 0x66B2FF
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define PINK 0xFFFFFF
# define SCALE 450
# define WIN_W 900
# define WIN_H 600
# define FOV (double)(M_PI / 3)
# define GRID_SIZE 32
# define MOVE_SPEED 3
# define LOOK_SPEED 0.03
# define ANG_BTW_RAY ((double)FOV / ((double)WIN_W / 2))

typedef struct s_inters
{
	double		ax;
	double		ay;
	double		offset_x;
	double		offset_y;
}				t_inters;

typedef struct s_cords
{
	int			x;
	int			y;
}				t_cords;

typedef struct s_dist_info
{
	double		distance;
	int			hor_or_ver;
}				t_dist_info;

typedef struct s_img
{
	void		*img;
	int			h;
	int			w;
}				t_img;

typedef struct s_player
{
	t_cords		p;
	double		a;
}				t_player;

typedef struct s_assets
{
	t_img		imgn;
	t_img		imgs;
	t_img		imge;
	t_img		imgw;
	int			color_floor;
	int			color_celing;
}				t_assets;

typedef struct s_state
{
	double angle;     //def = -1
	double lookspeep; //def =0
}				t_state;

typedef struct s_wall
{
	int			x_text;
	int			y_text;
	void		*texture;
}				t_wall;

typedef struct s_vars
{
	int			i;
	char		**map;
	int			size_map;
	t_player	p;
	t_assets	imgs;
	void		*mlx;
	void		*win;
	void		*img_ptr;
	long		wall_color;
	t_wall		wall;
	t_state		state;
	t_cords		mouse_pos;
}				t_vars;

#endif
