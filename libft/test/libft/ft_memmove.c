/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:48:27 by ohw               #+#    #+#             */
/*   Updated: 2021/11/16 12:08:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int size_t;

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
		i = len - 1;
		while (i >= 0)
		{
			*((char *)dst + i) = *((const char *)src + i);
			i --;
		}
	}
	return (dst);
}
