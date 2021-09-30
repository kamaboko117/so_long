/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:55:33 by asaboure          #+#    #+#             */
/*   Updated: 2021/09/30 17:56:20 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	isempty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& line[i] != '\t' && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	isplayer(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}

int	isrow(char *row)
{
	int	i;

	i = 0;
	if (isempty(row))
		return (0);
	while (row[i])
	{
		if (row[i] != '0' && row[i] != '1' && !isplayer(row[i]) && row[i] != 'C' &&
				row[i] != 'E')
			return (0);
		i++;
	}
	return (1);
}