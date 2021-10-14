/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:51:30 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/14 17:36:39 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parsing_exit_failure(char *error, char *line, t_data *data)
{
	free(line);
	exit_failure(error, data);
}

static void	get_map(char *line, t_data *data)
{
	int	i;

	ft_strjoin_free(&(data->map->tmpmap), line);
	ft_strjoin_free(&(data->map->tmpmap), "\n");
	i = -1;
	while (line[++i])
	{
		if (isplayer(line[i]))
		{
			data->player->count++;
		}
	}
}

void	get_ber_data(char *line, t_data *data)
{
	if (data->map_started == 1)
	{
		if (data->map_stopped == 1 && !isempty(line))
			data->error = "Map has a format error (1)\n";
		if (isempty(line))
			data->map_stopped = 1;
		else if (isrow(line))
			get_map(line, data);
		else
			data->error = "Map has a format error (2)\n";
	}
	else
	{
		if (isrow(line))
		{
			data->map_started = 1;
			get_map(line, data);
		}
		else
			data->error = "Map has a format error (3)\n";
	}
}

void	read_ber(char *ber_path, t_data *data)
{
	int			fd;
	char		*line;

	fd = open(ber_path, O_RDONLY);
	if (fd < 0)
		exit_failure("The file doesn't exist\n", data);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			get_ber_data(line, data);
			free(line);
		}
		get_ber_data(line, data);
		free(line);
		check_ber_data(data);
		get_layout(data);
		check_layout(data, data->map, data->player);
		data->win_h = data->map->map_y * data->map->map_s;
		data->win_w = data->map->map_x * data->map->map_s;
		check_dimensions(data, &(data->win_w), &(data->win_h));
	}
}
