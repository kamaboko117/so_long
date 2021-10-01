/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:53:07 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 03:05:14 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_loop(t_data *data)
{
	printf("entered loop\n");
	//get_texture(data);
	//data->mlx_win = mlx_new_window(data->mlx_ptr,
	//		 data->win_w, data->win_h, "So_long");
	data->mlx_win = mlx_new_window(data->mlx_ptr, 512, 512, "So_long");
	printf("plouf\n");
	if (data->mlx_win == NULL)
		exit_failure("failed to create mlx window\n", data);
	//create_hooks(data);
	data->img->img = mlx_new_image(data->mlx_ptr, data->win_w, data->win_h);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, &data
			->img->line_len, &data->img->endian);
	data->img->height = data->win_h;
	data->img->width = data->win_w;
	//imgdrawbg(data->img, data->win_w, data->win_h, data);
	//data->player->x = data->player->x * data->map->map_s + data->map->map_s / 2;
	//data->player->y = data->player->y * data->map->map_s + data->map->map_s / 2;
	//raycast(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	//mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	mlx_loop(data->mlx_ptr);
}