/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:31:24 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 01:51:35 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstlast(t_list *lst)
{
	while (lst -> next)
	   lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
		(ft_lstlast(*lst)) -> next = new;
}

//이미 추가된 노드를 다시 추가하는 경우
//인자로 널포인터가 들어오는 경우(즉, 빈 리스트에 삽입이 가능한지)
