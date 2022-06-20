/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:36:01 by hoh               #+#    #+#             */
/*   Updated: 2022/06/20 11:36:02 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	start_simulation(int n, t_philo *philo)
{
	int				i;
	struct timeval	mytime;

	i = 0;
	while (i < philo->sh_info->philo_num)
	{
		sem_post(philo->sh_info->sim_start[n - 1]);
		i ++;
	}
	i = 0;
	while (i < philo->sh_info->philo_num)
		sem_wait(philo->sh_info->sim_start[i ++]);
	pthread_mutex_lock(&(philo->sh_info->mutex_c));
	gettimeofday(&mytime, 0);
	philo->former = stamp(mytime.tv_sec, mytime.tv_usec, philo);
	philo->sh_info->start = 1;
	pthread_mutex_unlock(&(philo->sh_info->mutex_c));
}

static void	simulation(int n, t_philo *philo)
{
	while (philo->state != philo->sh_info->must_eat)
	{
		fork_sem_lock(n, philo);
		eating(n, philo);
		fork_sem_unlock(philo);
		sleeping(n, philo);
		thinking(n, philo);
	}
}

void	routine(int n, t_philo *philo)
{
	start_simulation(n, philo);
	simulation(n, philo);
}
