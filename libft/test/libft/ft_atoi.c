/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:43:43 by ohw               #+#    #+#             */
/*   Updated: 2021/11/24 16:58:50 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LONG_MAX 9223372036854775807
#define LONG_MIN -9223372036854775808

int	ft_atoi(const char *str)
{
	long long	ret;
	int			n;
	int			i;

	i = 0;
	n = 0;
	ret = 0;
	while ((9 <= *str && *str <= 13) | (*str == 32))
		str ++;
	if (*str == '+' | *str == '-')
	{	
		if (*str == '-')
			n ++;
		str ++;
	}			
	while (48 <= *str && *str <= 57)
	{	
		i ++;
		if (i == 19)
		{
			if (ret > (LONG_MAX) / 10)
				return ((int)LONG_MAX);
			else if (ret == (LONG_MAX) / 10)
			{
				if (n == 1 && *str - 48 >= 8)
					return (0);
				else if (n == 0 && *str - 48 > 7)
					return ((int)LONG_MAX);
			}
		}
		if (i > 19 && n == 1)
			return (0);
		else if (i > 19 && n == 0)
			return ((int)LONG_MAX);
		ret *= 10;
		ret = ret + *str - 48;
		str ++;
	}
	if (n % 2 == 1)
		return ((int)(-ret));
	else
		return ((int)ret);
}
