/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalahce <jbalahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:57:56 by monabid           #+#    #+#             */
/*   Updated: 2023/04/27 13:48:48 by jbalahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "cub3d_types.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//errors
void		malloc_err(void);
void		args_err(void);
void		file_err(void);
void		invalid_line_err(char *line, char *str);
void		error_exit(t_vars *vars, char *msg);
//utils
void		ft_free_split(char **split);
int			ft_isstr_digit(char *c);
int			get_win_heigth(char **map);
int			ft_isspace(char c);
void		end_game(t_vars *vars);
//hex
char		dig_to_hex(int i);
char		hex_to_dig(char i);
int			hex_to_int(char *hex_val);
//get_rgb
int			ft_atoi_rgb(char *str, char **split);
void		get_rgbval(char *line, void *to_set);
int			check_spit_content(char **split);
//get_imgpath
void		get_imgpath(char *line, void *to_set);
//gnl
char		*get_next_line(int fd);
//validaion
void		validation(t_vars *vars, char **argv);
//check_content
void		get_elements(t_vars *vars, int fd);
void		init_vars(t_vars *vars);
void		get_attr(char *line, t_vars *vars);
void		ft_remove_char(char *c, int index);
void		setup_val(char *line, void *to_set, int name);
void		check_content(t_vars *vars, char *path);
//ft_map
void		handle_map(t_vars *vars, int fd);

/*-------------- RAYCASTING ---------------- */
//file1.c (5 func)
void		get_pos(t_cords *cords, char **map, char c);
void		init_player(t_vars *vars);
t_inters	init_inters(double ax, double ay, double offset_x, double offset_y);
void		check_hor_inters(t_vars *vars, t_inters *horizontal, double ray);
//file2.c (5 func)
void		correct_angle(double *angle);
void		check_ver_inters(t_vars *vars, t_inters *vertical, double ray);
void		find_hor_wall(t_vars *vars, t_inters *horizontal, double ray);
void		find_ver_wall(t_vars *vars, t_inters *vertical, double ray);

//file3.c (5 func)
t_dist_info	cal_wall_dist(t_vars *vars, t_inters *horizontal,
				t_inters *vertical);
void		my_put_pixel_to_image(void *img_ptr, int x, int y, int color);
void		draw_flr_ceil(t_vars *vars);
void		draw_colomn(t_vars *vars, t_dist_info dist_info);
int			cast_rays(t_vars *vars);

//file3.c (5 func)
void		find_wall(t_vars *vars, double ray);
int			handle_key(t_vars *vars, double offset_angle);
int			move_player(int key, t_vars *vars);
int			release_btn(int key, t_vars *vars);
int			cross_mark(void);
///testfile.c
void		draw_sqr(t_vars *vars, int x, int y, int color, int size);
void		draw_grid(t_vars *vars);
void		draw_ray(t_vars *vars, double distance, double ray);
void		put_string(t_vars *vars);

#endif
