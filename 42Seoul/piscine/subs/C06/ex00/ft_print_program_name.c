/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:04:56 by ohw               #+#    #+#             */
/*   Updated: 2021/10/24 21:08:18 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;

	i = 0;
	if (ac > 0)
	{
		while (av[0][i] != 0)
		{
			write(1, &av[0][i], 1);
			i ++;
		}
		write(1, "\n", 1);
	}
}
