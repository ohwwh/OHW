/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:35:09 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 11:37:12 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	i = ac - 1;
	if (ac > 1)
	{
		while (i > 0)
		{
			j = 0;
			while (av[i][j] != 0)
			{
				write(1, &av[i][j], 1);
				j ++;
			}
			write(1, "\n", 1);
			i --;
		}
	}
}
