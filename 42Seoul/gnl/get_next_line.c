/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:43:31 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:56:13 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (ret)
	{
		while (s1 && s1[i])
		{
			ret[i] = s1[i];
			i ++;
		}
		while (s2 && *s2)
		{
			ret[i] = *s2;
			i ++;
			s2 ++;
		}
		ret[i] = 0;
		free(s1);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		*chunk;
	char			temp[BUFFER_SIZE + 1];
	char			*ret;
	int				i;

	if (BUFFER_SIZE <= 0)
		return (0);
	ret = gnl_strndup(chunk, gnl_strlen(chunk), 1);
	ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	while (ret && !ft_strchr(ret, '\n') && read(fd, temp, BUFFER_SIZE) > 0)
	{
		ret = gnl_strjoin(ret, temp);
		ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
	}
	if (ret)
	{
		i = gnl_strnlen(ret);
		chunk = gnl_strndup(&ret[i], gnl_strlen(&ret[i]), 0);
		ret = gnl_strndup(ret, i, 1);
	}
	return (ret);
}
