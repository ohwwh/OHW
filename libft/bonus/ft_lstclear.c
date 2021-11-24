/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:36:03 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 01:40:18 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;

	while (*lst)
	{
		delnode = *lst;
		*lst = (*lst) -> next;
		del(delnode -> content);
		free(delnode);
	}
}
