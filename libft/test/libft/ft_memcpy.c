/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:00:15 by ohw               #+#    #+#             */
/*   Updated: 2021/11/24 11:51:33 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int size_t;

void	*ft_memcpy(void *dst, const void *restrict src, size_t n)
{
	size_t	i;

	if (dst || src)
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)dst + i) = *((const char *)src + i);
			i ++;
		}
	}
	return (dst);
}
