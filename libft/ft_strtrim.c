/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:25:14 by asaboure          #+#    #+#             */
/*   Updated: 2021/07/05 18:51:14 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static char	*ft_empty(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

static char	*ft_trim(char const *s1, size_t j, size_t k)
{
	size_t	i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (k - j + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (j <= k)
		ret[i++] = s1[j++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	k;
	char	*ret;

	ret = NULL;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
	{
		ret = ft_empty();
		return (ret);
	}
	j = start(s1, set);
	if (j == ft_strlen(s1))
	{
		ret = ft_empty();
		return (ret);
	}
	k = end(s1, set);
	ret = ft_trim(s1, j, k);
	return (ret);
}
