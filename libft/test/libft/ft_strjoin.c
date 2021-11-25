/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:09:55 by ohw               #+#    #+#             */
/*   Updated: 2021/11/25 17:12:35 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		buf;
	char	*ret;
	int		i;

	if (!s1 | !s2)
		return (0);
	i = 0;
	buf = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * buf);
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
