/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:01:17 by asaboure          #+#    #+#             */
/*   Updated: 2021/09/30 17:55:10 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	int		map_x;
	int		map_y;
//	int		map_s;
	int		**map;
	char	*tmpmap;
}				t_map;

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
	t_map		*map;
}				t_data;

t_map	*mapstructinit(void);
void	exit_failure(char *error, t_data *data);
void	puterror(char *str);
t_data	*datainit(void);
void	read_ber(char *ber_path, t_data *data);
int	isempty(char *line);
int	isplayer(char c);
int	isrow(char *row);