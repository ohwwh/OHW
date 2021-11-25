/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:47:29 by ohw               #+#    #+#             */
/*   Updated: 2021/11/25 16:26:37 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

void	*ft_memmove(void *dst, const void *src, unsigned int len);
