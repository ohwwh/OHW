/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:30 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:31 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->objs[i])
		free(vars->objs[i ++]);
	free(vars->objs);
	free(vars->order_arr);
	free(vars->map);
}

void	ft_free_reset(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->objs[i])
		free(vars->objs[i ++]);
	free(vars->objs);
	free(vars->order_arr);
}
