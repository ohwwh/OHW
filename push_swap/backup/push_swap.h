/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:47:29 by ohw               #+#    #+#             */
/*   Updated: 2022/03/01 14:36:28 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775808U

typedef struct s_list
{
    int	content;
    struct s_list	*next;
    struct s_list	*prev;
}t_list;

t_list	*createNode(int num);
int		push(int num, t_list **lst);
int		pop(t_list **lst);
int		swap_stack(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
int		ft_atoi(const char *str);
void	swap(int *a, int *b);
void	sort(int *tab, int le, int re);
void	ft_sort_int_tab(int *tab, int size);
void	print2(int *arr, t_list **lstA);
void	print3(int *arr, t_list **lstA);
void	print_greedy(int *arr, t_list **lstA, t_list **lstB, int size);
#endif
