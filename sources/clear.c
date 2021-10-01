/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 02:44:09 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 03:38:39 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clear_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->tmpmap)
		free(data->map->tmpmap);
	if (data->map->map)
	{
		while (i < data->map->map_y)
			free(data->map->map[i++]);
		free(data->map->map);
	}
	free(data->map);
}

void	clear_image(t_imgdata *img, void *mlx)
{
	if (img->path)
		free(img->path);
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	free (img);
}

void	clear_window(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
}

void	clear_game(t_data *data)
{
	free(data->player);
	free(data->inputs);
	clear_map(data);
	clear_image(data->sp_texture, data->mlx_ptr);
	clear_image(data->img, data->mlx_ptr);
	clear_window(data);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}
