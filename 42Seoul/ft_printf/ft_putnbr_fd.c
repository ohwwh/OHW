/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:22:26 by ohw               #+#    #+#             */
/*   Updated: 2022/01/08 14:53:32 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	print(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		print(-n, fd);
	}
	else
		print(n, fd);
}
