/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:44:58 by ohw               #+#    #+#             */
/*   Updated: 2021/11/23 17:24:57 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int size_t;

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
