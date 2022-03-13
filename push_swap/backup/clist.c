/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:17:41 by ohw               #+#    #+#             */
/*   Updated: 2022/03/01 14:27:52 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*createNode(int num)
{
	t_list	*lst;
	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = num;
	lst -> next = lst;
	lst -> prev = lst;
	return (lst);
}

int	push(int num, t_list **lst)
{
	t_list	*newNode;

	newNode = createNode(num);
	if (!newNode)
		return (0);
	if(*lst)
	{
		newNode -> next = *lst;
		newNode -> prev = (*lst) -> prev;
		(*lst) -> prev -> next = newNode;
		(*lst) -> prev = newNode;
	}
	*lst = newNode;
	return (1);
}

int	pop(t_list **lst)
{
	t_list *delNode;

	if(*lst == 0)
		return (0);
	delNode = *lst;
	(*lst) -> next -> prev = (*lst) -> prev;
	(*lst) -> prev -> next = (*lst) -> next;
	*lst = (*lst) -> next;
	free(delNode);
	delNode = 0;
	return (1);
}

int	swap_stack(t_list **lst)
{
	t_list	*sec;

	if ((*lst == 0) | ((*lst) -> next == *lst))
		return (0);
	sec = (*lst) -> next;
	(*lst) -> next = sec -> next;
	sec -> next -> prev = *lst;
	sec -> next = *lst;
	sec -> prev = (*lst) -> prev;
	(*lst) -> prev -> next = sec;
	(*lst) -> prev = sec;
	(*lst) = sec;
	return (1);
}

void	rotate(t_list **lst)
{
	*lst = (*lst)->next;
}

void	reverse_rotate(t_list **lst)
{
	*lst = (*lst) -> prev;
}
