/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:55:59 by ohw               #+#    #+#             */
/*   Updated: 2022/03/01 15:07:29 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    int arr[argc - 1];
    int i;
    int j;
    t_list  *A;
    t_list  *B;

    i = 0;
	B = 0;
    while (i < argc - 1)
    {
		j = ft_atoi(argv[argc - 1 - i]);
        arr[argc - 2 - i] = j;
        push(j, &A);
        j = 0;
        while (j < i)
        {
            if (arr[argc - 2 - j] == arr[argc - 2 - i])
                return (0);
            j ++;
        }
        i ++;
    }
    print_greedy(arr, &A, &B, argc - 1);
}
