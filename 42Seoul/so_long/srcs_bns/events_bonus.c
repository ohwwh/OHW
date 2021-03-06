/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:26 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:27 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chase(t_vars *vars)
{
	int	c;

	c = vars->objs[0]->caught;
	if (vars->timer > 50)
	{
		if (!enemy_search_touch(vars, vars->objs[0]->caught))
			vars->objs[c]->state = vars->objs[c]->dir;
		else
		{
			vars->objs[c]->state = -1;
			vars->game_state = DEATH;
		}
	}
	vars->timer ++;
}

void	clear(t_vars *vars)
{
	const int	x = (vars->w * 64 - 640) / 2;
	const int	y = (vars->h * 64 - 400) / 2;

	vars->objs[0]->dir = 1;
	if (vars->timer > 10000)
	{
		mlx_clear_window(vars->mlx, vars->win);
		ft_img(vars, vars->clear, x, y);
	}
	vars->timer ++;
}

void	death(t_vars *vars)
{
	const int	x = (vars->w * 64 - 640) / 2;
	const int	y = (vars->h * 64 - 400) / 2;

	if (vars->timer > 10000)
	{
		mlx_clear_window(vars->mlx, vars->win);
		ft_img(vars, vars->game_over, x, y);
	}
	vars->timer ++;
}

int	close_game(t_vars *vars)
{
	ft_free(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
