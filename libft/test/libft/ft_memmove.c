/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:48:27 by ohw               #+#    #+#             */
/*   Updated: 2021/11/24 13:32:39 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//typedef unsigned int size_t;
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst < src)
	{	
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((const char *)src + i);
			i ++;
		}
	}
	else if (dst > src)
	{	
		i = len;
		while (i > 0)
		{
			*((char *)dst + i - 1) = *((const char *)src + i - 1);
			i --;
		}
	}
	return (dst);
}
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	char	*src = "this is a good nyancat !\r\n";
	//char	dst1[0xF0];
	char	dst2[0xF0];
	int		size = strlen(src);
	//printf("%s\n", ft_memmove(dst1, src, size));
	printf("%s\n", memmove(dst2, src, size));
}
