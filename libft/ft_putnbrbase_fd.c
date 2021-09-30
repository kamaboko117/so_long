/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:23:37 by asaboure          #+#    #+#             */
/*   Updated: 2021/07/05 17:49:08 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

static void	ft_recurr(long n, int fd, int baselen, char *base)
{
	char	a;

	if (n <= -baselen)
	{
		ft_recurr(n / baselen, fd, baselen, base);
		ft_recurr(n % baselen, fd, baselen, base);
	}
	else
	{
		a = base[-n];
		write(fd, &a, 1);
	}
}

void	ft_putnbrbase_fd(long n, char *base, int fd)
{
	if (check_base(base))
	{
		if (n < 0)
			write(fd, "-", 1);
		else
			n = -n;
		ft_recurr(n, fd, ft_strlen(base), base);
	}
}
