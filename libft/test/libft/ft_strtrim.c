/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:03:13 by ohw               #+#    #+#             */
/*   Updated: 2021/11/25 17:58:10 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_isset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set ++;
	}
	return (0);
}

static char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i] != 0)
		i ++;
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (ret)
	{
		i = 0;
		while (src[i] != 0)
		{
			ret[i] = src[i];
			i ++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*temp;
	char	*ret;

	temp = (char *)s1;
	while (ft_isset(*temp, set))
		temp ++;
	start = temp;
	while (*temp)
		temp ++;
	temp --;
	while (ft_isset(*temp, set))
		temp --;
	temp ++;
	while (ft_isset(*temp, set))
	{
		*temp = 0;
		temp ++;
	}
	ret = ft_strdup(start);
	return (ret);
}
