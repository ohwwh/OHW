/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:43:31 by ohw               #+#    #+#             */
/*   Updated: 2021/12/16 01:46:33 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_nsplit(char *src, char **start)
{
	char *ret;
	char *tmpfree;
	int i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
		{
			i ++;
			break;
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

void ft_ncut(char *src, char **start)
{
	char *tmpfree;
	int i;

	if (!src)
		return;
	i = 0;
	while (src[i] != '\n')
		i ++;
	tmpfree = *start;
	*start = ft_strdup(&src[i + 1]);
	free(tmpfree);
	src[i + 1] = 0;
}

char    *get_next_line(int fd)
{
	static char *start;
	char    temp[BUFFER_SIZE + 1];
	char    *ret;
	char    *tmpfree;
	int     flag;

	if ((BUFFER_SIZE == -1) | (!BUFFER_SIZE))
		return (0);
	flag = 0;
	ret = ft_nsplit(start, &start);
	ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(ret, '\n') && read(fd, temp, BUFFER_SIZE) > 0 && !flag)
	{
		tmpfree = ret;
		if (ft_strchr(temp, '\n'))
		{
			ft_ncut(temp, &start);
			flag ++;
		}
		ret = ft_strjoin(ret, temp);
		free(tmpfree);
		ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	}
	return (ret);
}
