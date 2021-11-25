/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:48:27 by ohw               #+#    #+#             */
/*   Updated: 2021/11/25 16:13:53 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int	i;

	if (dst < src)
	{	
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
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
