/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:48:17 by hoh               #+#    #+#             */
/*   Updated: 2022/04/28 11:48:19 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_release_w(t_vars *vars)
{
	if (vars->objs[0]->state == WD)
		vars->objs[0]->state = D;
	else if (vars->objs[0]->state == WA)
		vars->objs[0]->state = A;
	else
		vars->objs[0]->state = STAY;
}

void	key_release_a(t_vars *vars)
{
	if (vars->objs[0]->state == WA)
		vars->objs[0]->state = W;
	else if (vars->objs[0]->state == SA)
		vars->objs[0]->state = S;
	else
		vars->objs[0]->state = STAY;
}

void	key_release_s(t_vars *vars)
{
	if (vars->objs[0]->state == SD)
		vars->objs[0]->state = D;
	else if (vars->objs[0]->state == SA)
		vars->objs[0]->state = A;
	else
		vars->objs[0]->state = STAY;
}

void	key_release_d(t_vars *vars)
{
	if (vars->objs[0]->state == WD)
		vars->objs[0]->state = W;
	else if (vars->objs[0]->state == SD)
		vars->objs[0]->state = S;
	else
		vars->objs[0]->state = STAY;
}
