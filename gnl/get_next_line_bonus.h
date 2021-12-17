/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:07:58 by ohw               #+#    #+#             */
/*   Updated: 2021/12/17 00:58:08 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node{
	int				fd;
	char			*start;
	struct s_node	*next;
}t_node;

size_t	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *dst, char *src, size_t n);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
t_node	*find_create_node(int fd, t_node **lst);
void	delete_node(t_node **lst, int fd);
char	*ft_nsplit(char *src, char **start);
char	*get_next_line(int fd);

#endif
