/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:19:46 by asaboure          #+#    #+#             */
/*   Updated: 2019/11/27 17:44:28 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	void	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	l = &(**lst);
	tmp = l;
	while (tmp)
	{
		l = tmp;
		del(l->content);
		tmp = l->next;
		free(l);
	}
	*lst = NULL;
}
