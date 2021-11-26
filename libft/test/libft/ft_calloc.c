/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:09:15 by hoh               #+#    #+#             */
/*   Updated: 2021/11/26 16:35:14 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (!count | !size)
	{
		count = 1;
		size = 1;
	}
	ret = malloc(count * size);
	if (ret)
		ft_bzero(ret, count * size);
	return (ret);
}
