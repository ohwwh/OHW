/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:41:44 by hoh               #+#    #+#             */
/*   Updated: 2021/11/16 19:13:01 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		buf;
	int		temp;
	int		temp2;
	char	*ret;

	temp = n;
	temp2 = n;
	buf = 1;
	if (temp <= 0)
	{	
		buf ++;
		temp *= -1;
		temp2 *= -1;
	}
	while (temp)
	{
		temp /= 10;
		buf ++;
	}
	ret = (char *)malloc(sizeof(char) * buf);
	if (ret)
	{
		ret[buf - 1] = 0;
		buf --;
		while (temp2)
		{
			ret[buf - 1] = temp2 % 10 + '0';
			temp2 /= 10;
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
	ret = ft_itoa(-2333);
	printf("%s\n", ret);
	free(ret);
}
