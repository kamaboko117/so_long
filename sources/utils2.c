/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:14:52 by asaboure          #+#    #+#             */
/*   Updated: 2021/10/02 16:29:13 by asaboure         ###   ########.fr       */
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
