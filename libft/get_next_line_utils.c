/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:42:44 by asaboure          #+#    #+#             */
/*   Updated: 2021/07/23 19:51:44 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_nl(char *s1, int j)
{
	char	*ret;
	size_t	i;

	i = ft_strlen_nl(s1);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	if (j == 1)
		free(s1);
	return (ret);
}
