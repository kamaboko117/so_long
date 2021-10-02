/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:01:17 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/02 16:30:17 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BACKGROUND_COLOR 0x642E7C

typedef struct s_inputs
{
	char	w;
	char	a;
	char	s;
	char	d;
}				t_inputs;

typedef struct s_player
{
	int	x;
	int	y;
	int	count;
	int	frame;
	int	idle;
}				t_player;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	char	*path;
}				t_imgdata;

typedef struct s_map
{
	int						map_x;
	int						map_y;
	int						map_s;
	long unsigned int		line_len;
	int						**map;
	char					*tmpmap;
}				t_map;

typedef struct s_pos
{
	int	y;
	int	x;
	int	z;
	int	color;
}				t_pos;

typedef struct s_data
{
	int			win_h;
	int			win_w;
	void		*mlx_ptr;
	void		*mlx_win;
	int			map_started;
	int			map_stopped;
	t_inputs	*inputs;
	t_player	*player;
	t_imgdata	*img;
	t_imgdata	*sp_texture;
	t_imgdata	*tiles;
	t_map		*map;
}				t_data;

t_map	*mapstructinit(void);
void	exit_failure(char *error, t_data *data);
void	puterror(char *str);
t_data	*datainit(void);
void	read_ber(char *ber_path, t_data *data);
int		isempty(char *line);
int		isplayer(char c);
int		isrow(char *row);
void	clear_game(t_data *data);
void	game_loop(t_data *data);
void	check_ber_data(t_data *data);
void	get_layout(t_data *data);
void	set_player_position(t_player *player, int pos_x, int pos_y);
void	free_split(char **str);
void	check_layout(t_data *data, t_map *map, t_player *player);
int		exit_so_long(t_data *data);
void	imgdrawbg(t_imgdata *img, int xres, int yres);
void	set_texture(t_data *data, t_imgdata *texture);
void	draw_wall(t_data *data, t_pos p);
t_pos	setpos(int x, int y);
void	draw_layout(t_data *data);
void	check_dimensions(t_data *data, int *width, int *height);
void	draw_character(t_data *data);
void	up(t_player *player, int velocity, t_data *data);
void	left(t_player *player, int velocity, t_data *data);
void	down(t_player *player, int velocity, t_data *data);
void	right(t_player *player, int velocity, t_data *data);
#endif