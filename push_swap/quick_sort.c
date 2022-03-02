/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:28:26 by ohw               #+#    #+#             */
/*   Updated: 2022/03/01 14:29:39 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
    int	temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void	sort(int *tab, int le, int re)
{
    int	pivot;
    int	left;
    int	right;

    if (le >= re)
        return ;
    pivot = tab[le];
    left = le + 1;
    right = re;
    while (left <= right)
    {
        while (left <= right && tab[right] >= pivot)
            right --;
        while (left <= right && tab[left] <= pivot)
            left ++;
        if (left <= right)
            swap(&tab[left], &tab[right]);
    }
    swap(&tab[le], &tab[right]);
    sort(tab, le, right - 1);
    sort(tab, right + 1, re);
}

void	ft_sort_int_tab(int *tab, int size)
{
    sort(tab, 0, size - 1);
}
