/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:04:21 by ohw               #+#    #+#             */
/*   Updated: 2021/12/17 15:17:00 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
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

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	ret = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (ret)
	{
		i = 0;
		while (src && src[i])
		{
			ret[i] = src[i];
			i ++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if (!c)
		return ((char *)s);
	return (0);
}
