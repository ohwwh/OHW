/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:58:51 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 17:24:34 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{	
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 1;
	while (i <= n && (*s1 != '\0' | *s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (i == n && *s1 == *s2)
			return (0);
		s1 ++;
		s2 ++;
		i ++;
	}
	return (*s1 - *s2);
}
