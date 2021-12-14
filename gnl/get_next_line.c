/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:43:31 by ohw               #+#    #+#             */
/*   Updated: 2021/12/12 17:18:47 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	start_trim(char *ret, char *start)
{
    char    *origin;
    char    temp[BUFFER_SIZE];
    int     i;

    i = 0;
    origin = start;
    ft_bzero(ret, BUFFER_SIZE);
    while (*start && *start != '\n')
    {
        start ++;
        i ++;
    }
    if (*start == '\n')
        i ++;
    ft_strncpy(ret, origin, i);
    i = ft_strlen(++ start);
    ft_strncpy(temp, start, BUFFER_SIZE);
    ft_bzero(origin, BUFFER_SIZE);
    ft_strncpy(origin, temp, i);
}

char	*last_trim(char *src)
{
	char	*ret;

	if (!src)
		return (0);
	else if (!*src)
	{
		free(src);
		return (0);
	}
	else
	{
		ret = (char *)malloc(sizeof(char) * ft_strlen(src));
		ft_strncpy(ret, src, ft_strlen(src));
		free(src);
		return (ret);
	}
}

char	*join_trim(char *s1, char *s2, char *start, int *flag)
{
    char	*ret;
    int		i;

    i = istheren(s1, s2, start);
    if (i == 1)
    {
        ft_strlcat(start, s2, BUFFER_SIZE);
        return (s1);
    }
    else if (i == 2)
        (*flag) ++;
    ret = ft_strjoin(s1, s2);
    free(s1);
    return (ret);
}

char	*get_next_line(int fd)
{
    char		*ret;
    static char	start[BUFFER_SIZE] = {0,};
    char		temp[BUFFER_SIZE + 1];
    int			end;

    end = 0;
    ret = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!ret)
        return (0);
    start_trim(ret, start);
    ft_bzero(temp, sizeof(char) * (BUFFER_SIZE + 1));
    while (!end && read(fd, temp, BUFFER_SIZE))
    {
        ret = join_trim(ret, temp, start, &end);
        if (!ret)
            return (0);
        ft_bzero(temp, BUFFER_SIZE + 1);
    }
    return (last_trim(ret));
}
