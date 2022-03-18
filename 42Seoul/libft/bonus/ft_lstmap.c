/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:37:40 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 22:52:57 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new -> content = content;
		new -> next = 0;
	}
	return (new);
}

static void	ft_lstclear(t_list **lst, void (*del)(void *))
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

static t_list	*ft_lstlast(t_list *lst)
{
	while (lst -> next)
	   lst = lst -> next;
	return (lst);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
		(ft_lstlast(*lst)) -> next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	ret = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (new)
			ft_lstadd_back(&ret, new);
		else
		{
			ft_lstclear(&ret, del);
			return (ret);
		}
		lst = lst -> next;
	}
	return (ret);
}
