/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:34:48 by ohw               #+#    #+#             */
/*   Updated: 2022/03/13 14:48:45 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i ++;
	}
}

int	end_return(int ret, t_list **lstA, t_list **lstB)
{
	delete_lst(lstA);
	delete_lst(lstB);
	if (ret)
		return (print_error());
	else
		return (0);
}
