/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:04:13 by hoh               #+#    #+#             */
/*   Updated: 2021/11/16 16:08:55 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n -- > 0)
	{
		if (*((char *)s1 ++) != *((char *)s2 ++))
		return (-1);
	}
	return (1);
}
//컴파일 해볼 것
