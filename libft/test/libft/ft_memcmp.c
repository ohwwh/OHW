/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:04:13 by hoh               #+#    #+#             */
/*   Updated: 2021/11/26 15:07:54 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n -- > 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
		s1 ++;
		s2 ++;
	}
	return (0);
}
