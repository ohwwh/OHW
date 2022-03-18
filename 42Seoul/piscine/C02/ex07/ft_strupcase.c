/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:17:48 by hoh               #+#    #+#             */
/*   Updated: 2021/10/18 15:36:50 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char *origin;

	origin = str;
	while (*str != '\0')
	{	
		if (96 < *str && *str < 123)
		{
			*str -= 32;
		}
		str ++;
	}
	return (origin);
}

int	main(void)
{
	char str[6] = "Hello";
	ft_strupcase(str);
	printf("%s", str);
}

