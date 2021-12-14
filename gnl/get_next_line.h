/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:07:58 by ohw               #+#    #+#             */
/*   Updated: 2021/12/10 03:38:26 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>


size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *dst, char *src, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *dst, char *src, size_t n);
int		istheren(char *str1, char *str2, char *start);
char	*get_next_line(int fd);

#endif
