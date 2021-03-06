/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:32:37 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/14 19:07:40 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_sprite	*sprite_struct_init(t_data *data)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		exit_failure("malloc error\n", data);
	sprite->draw_start_x = 0;
	sprite->draw_end_x = 0;
	sprite->draw_start_y = 0;
	sprite->draw_end_y = 0;
	sprite->sprite_screen_x = 0;
	sprite->tx = 0;
	sprite->txoffset = 0;
	sprite->ty = 0;
	sprite->tyoffset = 0;
	sprite->img = imgstructinit(data);
	if (sprite->img == NULL)
		exit_failure("malloc error\n", data);
	return (sprite);
}

void	set_mlx(t_data *data)
{
	data->mlx_win = NULL;
	data->mlx_ptr = NULL;
}

t_collectibles	collectiblestructinit(t_data *data)
{
	t_collectibles	sushi;

	sushi.img = imgstructinit(data);
	sushi.max = 0;
	sushi.current = 0;
	return (sushi);
}
