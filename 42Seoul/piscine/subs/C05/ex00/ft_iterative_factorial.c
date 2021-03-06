/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:45:57 by ohw               #+#    #+#             */
/*   Updated: 2021/10/21 12:12:31 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	ret = 1;
	while (nb > 1)
	{
		ret *= nb;
		nb --;
	}
	return (ret);
}
