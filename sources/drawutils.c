/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 04:56:24 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/02 16:22:31 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	imgputpixel(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	imgdrawbg(t_imgdata *img, int xres, int yres)
{
	int	i;

	while (xres >= 0)
	{
		i = yres;
		while (i >= 0)
		{
			imgputpixel(img, xres, i, BACKGROUND_COLOR);
			i--;
		}
		xres--;
	}
}

void	draw_wall(t_data *data, t_pos p)
{
	int		i;
	int		j;
	char	*ce;

	ce = data->tiles->addr;
	j = 0;
	while (j < 35)
	{
		i = 0;
		while (i < 35)
		{
			imgputpixel(data->img, p.x + i, p.y + j, *(unsigned int *)(ce + (j
						* data->tiles->bpp / 8) + (i * data->tiles->line_len)));
			i++;
		}
		j++;
	}
}

void	draw_layout(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map->map_y)
	{
		i = 0;
		while (i < data->map->map_x)
		{
			if (data->map->map[j][i] == 1)
				draw_wall(data, setpos(i * data->map->map_s, j
						* data->map->map_s));
			i++;
		}
		j++;
	}
}

void	draw_character(t_data *data)
{
	int				i;
	int				j;
	char			*ch;
	unsigned int	color;

	if (data->player->frame > 5)
		data->player->frame = 0;
	if (data->player->frame != 0)
		data->player->idle = 4;
	ch = data->sp_texture->addr;
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
