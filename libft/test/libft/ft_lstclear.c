/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:36:03 by ohw               #+#    #+#             */
/*   Updated: 2021/11/26 17:04:57 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;

	while (*lst)
	{
		delnode = *lst;
		*lst = (*lst)-> next;
		del(delnode -> content);
		free(delnode);
	}
}
