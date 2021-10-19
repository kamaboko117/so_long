/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:53:07 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/18 16:10:56 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_so_long(data);
	if (keycode == 119)
		up(data->player, data->map->map_s, data);
	if (keycode == 97)
		left(data->player, data->map->map_s, data);
	if (keycode == 115)
		down(data->player, data->map->map_s, data);
	if (keycode == 100)
		right(data->player, data->map->map_s, data);
	return (1);
}

int	key_realease_hook(int keycode, t_data *data)
{
	if (keycode == 119)
		data->inputs->w = 0;
	if (keycode == 97)
		data->inputs->a = 0;
	if (keycode == 115)
		data->inputs->s = 0;
	if (keycode == 100)
		data->inputs->d = 0;
	return (1);
}

void	create_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_realease_hook, data);
	mlx_hook(data->mlx_win, 33, 1L << 17, exit_so_long, data);
}

//	mlx_clear_window(data->mlx_ptr, data->mlx_win);
int	render_next_frame(t_data *data)
{
	imgdrawbg(data->img, data->win_w, data->win_h);
	draw_layout(data);
	draw_character(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	return (1);
}

void	game_loop(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			data->win_w, data->win_h, "So_long");
	if (data->mlx_win == NULL)
		exit_failure("failed to create mlx window\n", data);
	create_hooks(data);
	data->img->img = mlx_new_image(data->mlx_ptr, data->win_w, data->win_h);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, &data
			->img->line_len, &data->img->endian);
	data->img->height = data->win_h;
	data->img->width = data->win_w;
	set_texture(data, data->tiles);
	data->map->map_s = data->tiles->width;
	set_texture(data, data->sp_texture);
	set_texture(data, data->sushi.img);
	set_texture(data, data->exit);
	set_texture(data, data->gameover->img);
	imgdrawbg(data->img, data->win_w, data->win_h);
	draw_layout(data);
	data->player->x = data->player->x * data->map->map_s;
	data->player->y = data->player->y * data->map->map_s;
	draw_character(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	mlx_loop(data->mlx_ptr);
}
