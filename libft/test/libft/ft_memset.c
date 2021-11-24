/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:42:19 by ohw               #+#    #+#             */
/*   Updated: 2021/11/16 13:54:30 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int size_t;

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i ++;
	}
	return (b);
}
