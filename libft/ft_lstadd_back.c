/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:43:07 by asaboure          #+#    #+#             */
/*   Updated: 2019/12/04 17:51:11 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (alst == NULL)
		return ;
	lst = *alst;
	while (lst)
	{
		if (lst->next == 0)
		{
			lst->next = new;
			return ;
		}
		lst = lst->next;
	}
	*alst = new;
}
