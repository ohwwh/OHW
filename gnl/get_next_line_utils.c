/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:04:21 by ohw               #+#    #+#             */
/*   Updated: 2021/12/12 17:21:28 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	while (i < n)
	{
		dst[i] = 0;
		i ++;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	t;

	i = 0;
	j = 0;
	while (dst[i])
		i ++;
	t = i;
	while (i + 1 < size && src[j])
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	while (src[j])
		j ++;
	if (t >= size)
		return (j + size);
	else
		return (t + j);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i ++;
	}
}

int istheren(char *str1, char *str2, char *start)
{
    while (*str1)
    {
        if (*str1 == '\n')
            return (1);
        str1 ++;
    }
    while (*str2)
    {
        if (*str2 == '\n')
        {
            ft_strncpy(start, ++str2, BUFFER_SIZE);
            *str2 = 0;
            return (2);
        }
        str2 ++;
    }
    return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
    char	*ret;
    int		i;

    if (!s1 | !s2)
        return (0);
    i = 0;
    ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (ret)
    {
        while (*s1)
        {
            ret[i] = *s1;
            i ++;
            s1 ++;
        }
        while (*s2)
        {
            ret[i] = *s2;
            i ++;
            s2 ++;
        }
        ret[i] = 0;
    }
    return (ret);
}
