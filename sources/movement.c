/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:24:28 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/14 19:04:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkcollision(double x, double y, t_data *data)
{
	x = x / data->map->map_s;
	y = y / data->map->map_s;
	if (data->map->map[(int)y][(int)x] == 1)
		return (1);
	if (data->map->map[(int)y][(int)x] == 2)
	{
		data->map->map[(int)y][(int)x] = 0;
		data->sushi.current++;
	}
	if (data->map->map[(int)y][(int)x] == 3)
		return (2);
	return (0);
}

void	up(t_player *player, int velocity, t_data *data)
{
	if (checkcollision(player->x, player->y - velocity, data) != 1)
		player->y -= velocity;
	player->frame++;
	printf("moves: %d\n", ++data->moves);
	if (checkcollision(player->x, player->y, data) == 2)
	{
		imgdrawbg(data->img, data->win_w, data->win_h);
		draw_layout(data);
		draw_character(data);
		game_over(data);
	}
}

void	left(t_player *player, int velocity, t_data *data)
{
	if (checkcollision(player->x - velocity, player->y, data) != 1)
		player->x -= velocity;
	player->frame++;
	player->orientation = 1;
	printf("moves: %d\n", ++data->moves);
	if (checkcollision(player->x, player->y, data) == 2)
	{
		imgdrawbg(data->img, data->win_w, data->win_h);
		draw_layout(data);
		draw_character(data);
		game_over(data);
	}
}

void	down(t_player *player, int velocity, t_data *data)
{
	if (checkcollision(player->x, player->y + velocity, data) != 1)
		player->y += velocity;
	player->frame++;
	printf("moves: %d\n", ++data->moves);
	if (checkcollision(player->x, player->y, data) == 2)
	{
		imgdrawbg(data->img, data->win_w, data->win_h);
		draw_layout(data);
		draw_character(data);
		game_over(data);
	}
}

void	right(t_player *player, int velocity, t_data *data)
{
	if (checkcollision(player->x + velocity, player->y, data) != 1)
		player->x += velocity;
	player->frame++;
	player->orientation = 0;
	printf("moves: %d\n", ++data->moves);
	if (checkcollision(player->x, player->y, data) == 2)
	{
		imgdrawbg(data->img, data->win_w, data->win_h);
		draw_layout(data);
		draw_character(data);
		game_over(data);
	}
}
