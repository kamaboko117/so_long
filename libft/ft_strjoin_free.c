/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:34 by asaboure          #+#    #+#             */
/*   Updated: 2021/07/05 17:51:35 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strjoin_free(char **str, char *buf)
{
	char	*tmp;

	if (*str == NULL)
		*str = ft_strdup(buf);
	else if (**str == '\0')
	{
		free(*str);
		*str = ft_strdup(buf);
	}
	else
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
}
