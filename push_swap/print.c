/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:25:24 by ohw               #+#    #+#             */
/*   Updated: 2022/03/01 14:27:21 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print2(int *arr, t_list **lstA)
{
    if (arr[0] > arr[1])
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else
        return ;
}

void print3(int *arr, t_list **lstA)
{
    if (arr[0] <= arr[1] && arr[1] <= arr[2])
        return ;
    else if (arr[0] <= arr[2] && arr[2] <= arr[1])
    {
        printf("sa\n");
        swap_stack(lstA);
        printf("ra\n");
        rotate(lstA);
    }
    else if (arr[1] <= arr[0] && arr[0] <= arr[2])
    {
        printf("sa\n");
        swap_stack(lstA);
    }
    else if (arr[1] <= arr[2] && arr[2] <= arr[0])
    {
        printf("ra\n");
        rotate(lstA);
    }
    else if (arr[2] <= arr[0] && arr[0] <= arr[1])
    {
        printf("rra\n");
        reverse_rotate(lstA);
    }
    else if (arr[2] <= arr[1] && arr[1] <= arr[0])
    {
        printf("sa\n");
        printf("rra\n");
        swap_stack(lstA);
        reverse_rotate(lstA);
    }
}

void print_greedy(int *arr, t_list **lstA, t_list **lstB, int size)
{
    int i;
    int j;

    i = 1;
    j = 1;
    if (size == 2)
        print2(arr, lstA);
    else if (size == 3)
        print3(arr, lstA);
    else
    {
        printf("pb\n");
        push((*lstA) -> content, lstB);
        pop(lstA);
        print_greedy(arr + 1, lstA, lstB, size - 1);
        ft_sort_int_tab(arr + 1, size - 1);
        while ((i < size) && (arr[i] < arr[0]))
            i ++;
        while ((j < size) && (arr[size - j] > arr[0]))
            j ++;
        if (i <= j)
        {
            j = i;
            while (j > 1)
            {
                printf("ra\n");
                rotate(lstA);
                j --;
            }
            printf("pa\n");
            push((*lstB) -> content, lstA);
            pop(lstB);
            while (i > 1)
            {
                printf("rra\n");
                reverse_rotate(lstA);
                i --;
            }
        }
        else
        {
            i = j;
            while (j > 1)
            {
                printf("rra\n");
                reverse_rotate(lstA);
                j --;
            }
            printf("pa\n");
            push((*lstB) -> content, lstA);
            pop(lstB);
            while (i > 0)
            {
                printf("ra\n");
                rotate(lstA);
                i --;
            }
        }
    }
}
