/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 04:56:24 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/14 19:02:09 by asaboure         ###   ########.fr       */
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

void	draw_exit(t_data *data, t_pos p)
{
	int				i;
	int				j;
	char			*ex;
	unsigned int	color;

	if (data->sushi.current != data->sushi.max)
		return ;
	ex = data->exit->addr;
	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = *(unsigned int *)(ex + (i * data->exit->bpp / 8) + (j
						* data->exit->line_len));
			if (color != 0xFF000000)
				imgputpixel(data->img, p.x + i, p.y + j, color);
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
			if (data->map->map[j][i] == 2)
				draw_collectible(data, setpos(i * data->map->map_s, j
						* data->map->map_s));
			if (data->map->map[j][i] == 3)
				draw_exit(data, setpos(i * data->map->map_s, j
						* data->map->map_s));
			i++;
		}
		j++;
	}
}
