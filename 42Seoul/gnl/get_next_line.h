/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:07:58 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:54:31 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	gnl_strlen(char *str);
size_t	gnl_strnlen(char *str);
void	ft_bzero(void *s, size_t n);
char	*gnl_strndup(char *src, size_t n, int flag);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
