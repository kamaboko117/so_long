/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:43 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 21:38:05 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long n, int base)
{
	int	ret;

	ret = 1;
	while (n >= base || n <= -base)
	{
		ret++;
		n = n / base;
	}
	return (ret);
}
