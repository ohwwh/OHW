/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:36:11 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 21:43:51 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	wordcount(char const *s, char c)
{
    int	cnt;

    cnt = 0;
    while (*s)
    {
        if (*s != c)
        {
            cnt ++;
            while (*s && *s != c)
                s ++;
        }
        else
            s ++;
    }
    return (cnt);
}

static int	wordlen(char const *s, char c)
{
    int	i;

    i = 0;
    while (s[i] != c && s[i])
        i ++;
    return (i);
}

static char	*ft_strdup(const char *src, char c)
{
	int		i;
	char	*ret;

	ret = (char *)malloc((wordlen(src, c) + 1) * sizeof(char));
	if (ret != 0)
	{
		i = 0;
		while (src[i] && src[i] != c)
		{
			ret[i] = src[i];
			i ++;
		}
		ret[i] = 0;
		return (ret);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
    char	**ret;
	int		i;

	i = 0;
    ret = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
    while (*s)
    {
        if (*s != c && *s)
        {
            ret[i] = ft_strdup(s, c);           
			i ++;
			s += wordlen(s, c);
        }
        else
            s ++;
    }
	ret[i] = 0;
    return (ret);
}
