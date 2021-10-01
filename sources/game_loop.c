/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:53:07 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 21:45:43 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_so_long(data);
	if (keycode == 119)
		data->inputs->w = 1;
	if (keycode == 97)
		data->inputs->a = 1;
	if (keycode == 115)
		data->inputs->s = 1;
	if (keycode == 100)
		data->inputs->d = 1;
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

t_pos	setpos(int x, int y)
{
	t_pos	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	game_loop(t_data *data)
{
	set_texture(data, data->tiles);
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
	imgdrawbg(data->img, data->win_w, data->win_h);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	draw_layout(data);
	//mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	mlx_loop(data->mlx_ptr);
}
