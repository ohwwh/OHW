/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:48:27 by ohw               #+#    #+#             */
/*   Updated: 2021/11/11 10:10:53 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int size_t;

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buf;
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(buf + i) = *((char *)src + i);
		i ++;
	}
	i = 0;
	while (i < len)
	{
		*((char *)dst + i) = *(buf + i);
		i ++;
	}

}
