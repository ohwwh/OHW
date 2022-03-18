/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:03:13 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 21:44:47 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_isset(char const c, char const *set)
{
	while (set)
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
	//만약 s1에 널문자만 들어오거나 널포인터가 들어오는 경우는 어떻게 해야 하는가>
	char	*start;
	char	*temp;
	char	*ret;

	temp = (char *)s1;
	if (ft_isset(*temp, set))
		temp ++;
	start = temp;
	while (*temp)
		temp ++;
	temp --;
	if (ft_isset(*temp, set))
	  *temp = 0;
	ret = ft_strdup(start);
	return (ret);
}
#include <stdio.h>
int	main(void)
{
	char	str[100] = "Hello";
	char	set[100] = "Ho";
	char	*ret = ft_strtrim(str, set);
	printf("%s\n", ret);
	free(ret);
}
