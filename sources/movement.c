/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:24:28 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/02 16:25:41 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkcollision(double x, double y, t_data *data)
{
	x = x / data->map->map_s;
	y = y / data->map->map_s;
	if (data->map->map[(int)y][(int)x] >= 1)
		return (1);
	return (0);
}

void	up(t_player *player, int velocity, t_data *data)
{
	if (!checkcollision(player->x, player->y - velocity, data))
		player->y -= velocity;
	player->frame++;
}

void	left(t_player *player, int velocity, t_data *data)
{
	if (!checkcollision(player->x - velocity, player->y, data))
		player->x -= velocity;
	player->frame++;
}

void	down(t_player *player, int velocity, t_data *data)
{
	if (!checkcollision(player->x, player->y + velocity, data))
		player->y += velocity;
	player->frame++;
}

void	right(t_player *player, int velocity, t_data *data)
{
	if (!checkcollision(player->x + velocity, player->y, data))
		player->x += velocity;
	player->frame++;
}
