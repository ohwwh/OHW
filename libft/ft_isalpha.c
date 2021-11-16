/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:55:19 by hoh               #+#    #+#             */
/*   Updated: 2021/11/08 16:37:18 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{

	if (('a' <= c && c <= 'z') | ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
