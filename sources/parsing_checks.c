/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 03:11:54 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 22:33:16 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_ismap_char(char c)
{
	if (c == 'P' || c == 'C' || c == 'E')
		return (1);
	else if (c == '0' || c == '1' || c == '\n')
		return (1);
	return (0);
}

static void	check_map(t_data *data)
{
	int	i;

	if (!data->map)
		exit_failure("Missing map layout\n", data);
	else
	{
		i = 0;
		while (data->map->tmpmap[i])
		{
			if (!ft_ismap_char(data->map->tmpmap[i]))
				exit_failure("Wrong characters in the map layout\n", data);
			i++;
		}
		if (data->player->count == 0)
			exit_failure("No player in map\n", data);
	}
}

void	check_dimensions(t_data *data, int *width, int *height)
{
	int	max_x;
	int	max_y;

	max_y = 0;
	max_x = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit_failure("failed to initiate mlx instance\n", data);
	mlx_get_screen_size(data->mlx_ptr, &max_x, &max_y);
	if (*width < 100)
		*width = 100;
	if (*height < 100)
		*height = 100;
	if (*width >= max_x)
		*width = max_x;
	if (*height >= max_y)
		*height = max_y;
}

//check_texture
void	check_ber_data(t_data *data)
{
	check_map(data);
}
