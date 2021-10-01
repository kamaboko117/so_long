/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:45:58 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 04:26:36 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_imgdata	*imgstructinit(t_data *data)
{
	t_imgdata	*img;

	img = (t_imgdata *)malloc(sizeof(t_imgdata));
	if (img == NULL)
		exit_failure("malloc error\n", data);
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
	img->path = NULL;
	img->width = 0;
	img->height = 0;
	return (img);
}

t_player	*playerstructinit(void)
{
	t_player	*p;

	p = (t_player *)malloc(sizeof(t_player));
	if (p == NULL)
		return (NULL);
	p->x = 0;
	p->y = 0;
	p->count = 0;
	return (p);
}

t_map	*mapstructinit(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->map = NULL;
	map->tmpmap = NULL;
	map->map_x = 0;
	map->map_y = 0;
	map->map_s = 16;
	map->line_len = 0;
	return (map);
}

t_inputs	*inputstructinit(void)
{
	t_inputs	*inputs;

	inputs = (t_inputs *)malloc(sizeof (t_inputs));
	if (inputs == NULL)
		return (NULL);
	inputs->a = 0;
	inputs->d = 0;
	inputs->s = 0;
	inputs->w = 0;
	return (inputs);
}

t_data	*datainit(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->map_started = 0;
	data->map_stopped = 0;
	data->sp_texture = imgstructinit(data);
	data->img = imgstructinit(data);
	data->player = playerstructinit();
	data->map = mapstructinit();
	data->inputs = inputstructinit();
	if (!(data->sp_texture) || !(data->img)
		|| !(data->player) || !(data->map) || !(data->inputs))
		return (NULL);
	return (data);
}
