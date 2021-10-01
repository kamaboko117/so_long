/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 03:59:31 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 04:35:38 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	row_ternary(char c)
{
	int	i;

	i = 0;
	if (ft_isdigit(c))
		i = c - '0';
	return (i);
}

int	*get_row(char *line, t_data *data, int current_row)
{
	int	*row;
	int	i;

	row = (int *)malloc(sizeof(int) * data->map->map_x);
	if (!row)
		exit_failure("malloc error\n", data);
	i = 0;
	while (i < data->map->map_x)
	{
		while (line[i])
		{
			if (isplayer(line[i]))
			{
				set_position(data->player, i, current_row);
				row[i] = 0;
			}
			else
				row[i] = row_ternary(line[i]);
			i++;
		}
		while (i < data->map->map_x)
			row[i++] = 0;
	}
	return (row);
}

void	get_layout(t_data *data)
{
	char		**split_map;
	t_map		*map;
	int			i;

	map = data->map;
	split_map = ft_split(map->tmpmap, '\n');
	while (split_map[(int)map->map_y])
	{
		if (map->map_x < (int)ft_strlen(split_map[map->map_y]))
			map->map_x = (int)ft_strlen(split_map[map->map_y]);
		map->map_y++;
	}
	map->map = (int **)malloc(map->map_y * sizeof(int *));
	if (!(map->map))
		exit_failure("malloc error\n", data);
	i = 0;
	while (i < map->map_y)
	{
		map->map[i] = get_row(split_map[i], data, i);
		i++;
	}
	free_split(split_map);
}
