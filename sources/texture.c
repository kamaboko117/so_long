/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:34:39 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/02 13:40:00 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_texture(t_data *data, t_imgdata *texture)
{
	texture->img = mlx_xpm_file_to_image(data->mlx_ptr,
			texture->path,
			&texture->width,
			&texture->height);
	if (texture->img == NULL)
		exit_failure("Impossible to load a texture\n", data);
	texture->addr = mlx_get_data_addr(texture->img,
			&(texture->bpp),
			&(texture->line_len),
			&(texture->endian));
}
