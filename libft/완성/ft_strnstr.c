/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:44:58 by ohw               #+#    #+#             */
/*   Updated: 2021/11/16 16:08:00 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//typedef unsigned int size_t;
#include <stdio.h>
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*find;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while (*haystack == needle[i])
		{
			if (i == 0)
				find = (char *)haystack;
			haystack ++;
			len --;
			i ++;
			if (needle[i] == '\0')
				return (find);
			if (needle[i] != '\0' && (*haystack == '\0' | len == 0))
				return (0);
		}
		haystack ++;
		len --;
	}
	return (0);
}
int	main(void)
{
	char	haystack[100] = "HelloWorld";
	char	needle[100] = "llo";

	printf("%s\n", ft_strnstr(haystack, needle, 4));
}
