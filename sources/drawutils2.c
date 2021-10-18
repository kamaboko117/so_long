/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawutils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:31:09 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/18 16:08:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_collectible(t_data *data, t_pos p)
{
	int				i;
	int				j;
	char			*co;
	unsigned int	color;

	co = data->sushi.img->addr;
	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = *(unsigned int *)(co + (i * data->sushi.img->bpp / 8)
					+ (j * data->sushi.img->line_len));
			if (color != 0xFF000000)
				imgputpixel(data->img, p.x + i, p.y + j, color);
			i++;
		}
		j++;
	}
}

static void	normaldraw(t_data *data, char *ch)
{
	int				i;
	int				j;
	unsigned int	color;

	j = -1;
	while (j++ < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = *(unsigned int *)(ch + ((i + data->player->frame * 32)
						* data->sp_texture->bpp / 8) + ((j + 32 * data->player
							->idle) * data->sp_texture->line_len));
			if (color != 0xFF000000)
				imgputpixel(data->img, data->player->x + i, data->player->y + j,
					color);
			i++;
		}
	}
}

static void	mirrordraw(t_data *data, char *ch)
{
	int				i;
	int				j;
	unsigned int	color;

	j = -1;
	while (j++ < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = *(unsigned int *)(ch + ((i + data->player->frame * 32)
						* data->sp_texture->bpp / 8) + ((j + 32 * data->player
							->idle) * data->sp_texture->line_len));
			if (color != 0xFF000000)
				imgputpixel(data->img, data->player->x - i + 32, data->player->y
					+ j, color);
			i++;
		}
	}
}

void	draw_character(t_data *data)
{
	char			*ch;

	if (data->player->frame > 5)
		data->player->frame = 0;
	if (data->player->frame != 0)
		data->player->idle = 4;
	ch = data->sp_texture->addr;
	if (data->player->orientation == 0)
		normaldraw(data, ch);
	else
		mirrordraw(data, ch);
}
