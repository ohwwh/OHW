/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:43:31 by ohw               #+#    #+#             */
/*   Updated: 2021/12/17 15:32:54 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_node	*find_create_node(int fd, t_node **lst)
{
	t_node	*newnode;
	t_node	*target;

	target = *lst;
	while (target && target -> fd != fd && target -> next)
		target = target -> next;
	if (!target || (target -> fd != fd && !(target -> next)))
	{
		newnode = (t_node *)malloc(sizeof(t_node));
		newnode -> fd = fd;
		newnode -> start = 0;
		newnode -> next = 0;
		if (target && !(target -> next))
		{
			target -> next = newnode;
			target = target -> next;
		}
		else
		{
			*lst = newnode;
			target = newnode;
		}
	}
	return (target);
}

void	delete_node(t_node **lst, int fd)
{
	t_node	*prev;
	t_node	*target;

	prev = *lst;
	target = *lst;
	if (!target)
		return ;
	else if (target -> fd == fd)
	{
		prev = *lst;
		*lst = (*lst)-> next;
		free(prev -> start);
		free(prev);
		return ;
	}
	while (target -> fd != fd)
	{
		prev = target;
		target = target -> next;
	}
	prev -> next = target -> next;
	free(target);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret)
	{
		while (s1 && *s1)
		{
			ret[i] = *s1;
			i ++;
			s1 ++;
		}
		while (s2 && *s2)
		{
			ret[i] = *s2;
			i ++;
			s2 ++;
		}
		ret[i] = 0;
	}
	return (ret);
}

char	*ft_nsplit(char *src, char **start)
{
	char	*ret;
	char	*tmpfree;
	int		i;

	if (!src | !*src)
		return (0);
	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
		{
			i ++;
			break ;
		}
		i ++;
	}
	ret = (char *)malloc(sizeof(char) * (i + 1));
	ft_strncpy(ret, src, i);
	ret[i] = 0;
	tmpfree = *start;
	*start = ft_strdup(&src[i]);
	free(tmpfree);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_node	*lst;
	t_node			*start;
	char			temp[BUFFER_SIZE + 1];
	char			*ret;
	char			*tmpfree;

	if ((BUFFER_SIZE == -1) | (!BUFFER_SIZE))
		return (0);
	start = find_create_node(fd, &lst);
	ret = ft_strdup(start -> start);
	ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	while (ret && !ft_strchr(ret, '\n') && read(fd, temp, BUFFER_SIZE) > 0)
	{
		tmpfree = ret;
		ret = ft_strjoin(ret, temp);
		free(tmpfree);
		ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	}
	tmpfree = ret;
	ret = ft_nsplit(ret, &(start -> start));
	free(tmpfree);
	if (!ret)
		delete_node(&lst, fd);
	return (ret);
}
