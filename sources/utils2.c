/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:14:52 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/11 17:26:31 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_so_long(t_data *data)
{
	clear_game(data);
	exit(EXIT_SUCCESS);
}

t_pos	setpos(int x, int y)
{
	t_pos	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	set_data_paths(t_data *data)
{
	data->tiles->path = ft_strdup("textures/wall.xpm");
	data->sp_texture->path = ft_strdup("textures/Cat-Sprite-Sheet.xpm");
	data->c_texture->path = ft_strdup("textures/sushi.xpm");
	data->exit->path = ft_strdup("textures/portal.xpm");
	data->gameover->img->path = ft_strdup("textures/lvl_cleared.xpm");
}
