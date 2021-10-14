/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:29:51 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/14 13:35:43 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	gameover_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_so_long(data);
	return (1);
}

static void	draw(t_data *data, t_sprite *s, int i, int j)
{
	char	*src;

	src = data->gameover->img->addr + (int)s->ty * data->gameover->img
		->line_len + (int)s->tx * (data->gameover->img->bpp / 8);
	if (*(unsigned int *)src != 0xFF000000)
		*(unsigned int *)(data->img->addr + (j * data->img->line_len
					+ i * (data->img->bpp / 8))) = *(unsigned int *)src;
}

void	downscale(t_data *data, t_sprite *s)
{
	int		i;
	int		j;
	double	step;

	step = (double)s->img->height / (double)data->win_h;
	if (step < (double)s->img->width / (double)data->win_w)
		step = (double)s->img->width / (double)data->win_w;
	i = 0;
	s->tx = 0;
	while (s->tx < s->img->width)
	{
		s->ty = 0;
		j = 0;
		while (s->ty < s->img->height)
		{
			draw(data, s, i, j);
			s->ty += step;
			j++;
		}
		s->tx += step;
		i++;
	}
}

void	draw_img_scaled(t_data *data, t_sprite *s)
{
	if (s->img->height > data->win_h || s->img->width > data->win_w)
		downscale(data, s);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
}

int	game_over(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, gameover_key_hook, data);
	mlx_loop_hook(data->mlx_ptr, game_over, data);
	draw_img_scaled(data, data->gameover);
	return (0);
}
