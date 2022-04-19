#include "so_long.h"

void    reset_collect(t_vars *vars)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'c')
		{
			vars->map[i] = 'C';
			n ++;
		}
			
		i ++;
	}
	vars->collect_num = n;
}

void    reset(t_vars *vars)
{
	reset_collect(vars);
	init(vars);
	map_draw(vars);
}