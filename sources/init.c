/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:45:58 by asaboure          #+#    #+#             */
/*   Updated: 2021/09/30 17:52:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (map);
}

t_data	*datainit(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->map_started = 0;
	data->map_stopped = 0;
//	data->sp_texture = imgstructinit(data);
//	data->img = imgstructinit(data);
//	data->player = playerstructinit();
	data->map = mapstructinit();
//	data->inputs = inputstructinit();
//	if (!(data->sp_texture) || !(data->img)
//		|| !(data->player) || !(data->map) || !(data->inputs))
//		return (NULL);
	return (data);
}