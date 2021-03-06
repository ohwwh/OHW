/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:36:58 by hoh               #+#    #+#             */
/*   Updated: 2022/06/20 11:37:00 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	end_simulation(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(philo->sh_info->mutex_c));
	if (philo->sh_info->end >= philo->sh_info->philo_num)
	{
		pthread_mutex_unlock(&(philo->sh_info->mutex_c));
		ret = 1;
	}
	pthread_mutex_unlock(&(philo->sh_info->mutex_c));
	return (ret);
}

static void	end_philo(int j, t_philo *philo)
{
	if (philo[j].end == 1)
	{
		pthread_mutex_lock(&(philo->sh_info->mutex_c));
		philo->sh_info->end += 1;
		pthread_mutex_unlock(&(philo->sh_info->mutex_c));
		philo[j].end += 1;
	}
}

static void	check_death(int j, t_philo *philo)
{
	struct timeval	mytime;
	long			current_time;
	const int		time_to_die = philo->sh_info->time_to_die;

	gettimeofday(&mytime, 0);
	current_time = stamp(mytime.tv_sec, mytime.tv_usec, philo);
	if (philo[j].end < 1 && philo->sh_info->death != 1)
	{
		if (current_time - philo[j].former >= time_to_die)
		{
			pthread_mutex_lock(&(philo->sh_info->mutex_c));
			philo->sh_info->death = 1;
			printf("at %ld %dth died\n", current_time, j + 1);
			pthread_mutex_unlock(&(philo->sh_info->mutex_c));
		}
	}
}

static void	start_monitoring(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&(philo->sh_info->mutex_c));
		if (philo->sh_info->cnt == philo->sh_info->philo_num)
		{
			pthread_mutex_unlock(&(philo->sh_info->mutex_c));
			break ;
		}
		pthread_mutex_unlock(&(philo->sh_info->mutex_c));
	}
}

void	monitoring(t_philo *philo, int n)
{
	int	j;

	start_monitoring(philo);
	while (1)
	{
		j = 0;
		while (j < n)
		{
			pthread_mutex_lock(&(philo->sh_info->mutex_m[j]));
			end_philo(j, philo);
			check_death(j, philo);
			pthread_mutex_unlock(&(philo->sh_info->mutex_m[j]));
			j ++;
		}
		if (end_simulation(philo))
			break ;
	}
}
