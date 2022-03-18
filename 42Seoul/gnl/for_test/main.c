/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:58:46 by ohw               #+#    #+#             */
/*   Updated: 2022/03/16 12:45:19 by ohw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd;
	
	fd = open("/Users/ohw/42git/OHW/gnl/for_test/file", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	/*while (str)
	{
		str = get_next_line(0);
		printf("%s\n", str);
		free(str);
	}*/
}
