/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:34 by hoh               #+#    #+#             */
/*   Updated: 2021/11/23 22:34:46 by ohw              ###   ########.fr       */
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
