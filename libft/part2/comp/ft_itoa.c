/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:41:44 by hoh               #+#    #+#             */
/*   Updated: 2021/11/23 21:43:04 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	getbuf(int n)
{
	int	buf;

	buf = 1;
	if (n <= 0)
	{	
		buf ++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		buf ++;
	}
	return (buf);
}

char	*ft_itoa(int n)
{
	int		buf;
	int		temp;
	char	*ret;
	
	if (n >= 0)
		temp = n;
	else
		temp = -n;
	buf = getbuf(n);	
	ret = (char *)malloc(sizeof(char) * buf);
	if (ret)
	{
		ret[buf - 1] = 0;
		buf --;
		while (temp)
		{
			ret[buf - 1] = temp % 10 + '0';
			temp /= 10;
			buf --;
		}
		if (n < 0)
			ret[buf - 1] = '-';
		else if (n == 0)
			ret[buf - 1] = '0';
	}
	return (ret);
}
#include <stdio.h>
int	main(void)
{
	char	*ret;
	ret = ft_itoa(23333);
	printf("%s\n", ret);
	free(ret);
}
