/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:22:45 by ohw               #+#    #+#             */
/*   Updated: 2022/03/02 18:47:52 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int	n = atoi(argv[1]);
	int	arr[n];
	int	j;

	if (argc != 2)
		return (-1);
	srand(time(0));
	for (int i = 0; i < n; i ++)
	{
		j = rand() % 5;
		arr[i] = j;
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
			{
			   i --;
			   break;
			}
			j ++;
		}
	}
	for (int i = 0; i < n; i ++)
	{
		printf("%d", arr[i]);
		if (i != n - 1)
			printf(" ");
	}
}
