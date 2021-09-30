/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:37:25 by asaboure          #+#    #+#             */
/*   Updated: 2021/09/30 17:56:18 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *ber_path, t_data *data)
{
	read_ber(ber_path, data);
//	game_loop(data);
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
//	else if (argc == 2 && !checkargs(argv[1], NULL, data))
		so_long(argv[1], data);
	return (EXIT_SUCCESS);
}
