/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:34 by hoh               #+#    #+#             */
/*   Updated: 2021/11/16 18:41:35 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		while (i < len && s[start])
		{
			ret[i] = s[start];
			i ++;
			start ++;
		}
		ret[i] = 0;
	}
	return (ret);
}
#include <stdio.h>
int	main(void)
{
	char	str[100] = "Hello";
	char	*sub;
	sub = ft_substr(str, 1, 3);
	printf("%s\n", sub);
	free(sub);
}
