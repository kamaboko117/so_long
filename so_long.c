/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:37:25 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/01 04:35:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *ber_path, t_data *data)
{
	read_ber(ber_path, data);
	game_loop(data);
}

int	checkargs(char *cub_path, t_data *data)
{
	char	**path;
	int		path_len;

	path_len = 0;
	if (cub_path)
	{
		path = ft_split(cub_path, '.');
		while (path[path_len])
			path_len++;
		if (ft_strncmp(path[path_len - 1], "ber", 4))
			exit_failure("file is not a .ber type\n", data);
		free_split(path);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = datainit();
	if (data == NULL)
	{
		puterror("failed to allocate memory for data structure\n");
		exit (EXIT_FAILURE);
	}
	if (argc > 2 || argc < 2)
		exit_failure("wrong number of arguments\n", data);
	else if (argc == 2 && !checkargs(argv[1], data))
		so_long(argv[1], data);
	return (EXIT_SUCCESS);
}
