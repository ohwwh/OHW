/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:02:52 by ohw               #+#    #+#             */
/*   Updated: 2021/11/22 12:46:13 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
#include <stdio.h>
void	ft_printlst(t_list *lst)
{
	int	content;

	while (lst)
	{
		content = *((int *)(lst -> content));
		printf("%d ", content);
		lst = lst -> next;
	}
	printf("\n");
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size ++;
		lst = lst -> next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst -> next)
	   lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp = *lst;
	while ((*lst) -> next)
	{
		*lst = (*lst) -> next;
	}
	(*lst) ->next = new;
	*lst = temp;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;
	t_list	*new4;
	int		lstc = 0;
	int		new1c = 1;
	int		new2c = 2;
	int		new3c = 3;
	int		new4c = 4;


	lst = ft_lstnew(&lstc);
	new1 = ft_lstnew(&new1c);
	new2 = ft_lstnew(&new2c);
	ft_printlst(lst);
	ft_lstadd_front(&lst, new1);
	ft_printlst(lst);
	ft_lstadd_front(&lst, new2);
	ft_printlst(lst);
	printf("%d\n", ft_lstsize(lst));
	printf("%d\n", *((int *)(ft_lstlast(lst) -> content)));
	new3 = ft_lstnew(&new3c);
	new4 = ft_lstnew(&new4c);
	ft_lstadd_back(&lst, new3);
	ft_printlst(lst);
	ft_lstadd_back(&lst, new4);
	ft_printlst(lst);
}
