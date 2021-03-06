#include "philosopher.h"

void	fork_sem_lock(int n, t_philo *philo)
{
	if (n % 2 && philo->state == 0)
		ft_msleep(philo->sh_info->time_to_eat);
	sem_wait(philo->sh_info->deadlock_check);
	sem_wait(philo->sh_info->fork);
	sem_wait(philo->sh_info->fork);
}

void	fork_sem_unlock(t_philo *philo)
{
	sem_post(philo->sh_info->fork);
	sem_post(philo->sh_info->fork);
	sem_post(philo->sh_info->deadlock_check);
}

void	sleeping(int n, t_philo *philo)
{
	struct timeval	t;
	long			current;

	pthread_mutex_lock(&(philo->sh_info->mutex_c));
	if (philo->state != philo->sh_info->must_eat)
	{
		pthread_mutex_unlock(&(philo->sh_info->mutex_c));
		sem_wait(philo->sh_info->print);
		gettimeofday(&t, 0);
		current = stamp(t.tv_sec, t.tv_usec, philo);
		printf("at %ld %dth start sleeping", current, n);
		printf("                      [%d]\n", philo->state);
		sem_post(philo->sh_info->print);
		ft_msleep(philo->sh_info->time_to_sleep);
	}
	pthread_mutex_unlock(&(philo->sh_info->mutex_c));
}

void	thinking(int n, t_philo *philo)
{
	struct timeval	t;
	long			current;
	
	pthread_mutex_lock(&(philo->sh_info->mutex_c));
	if (philo->state != philo->sh_info->must_eat)
	{
		pthread_mutex_unlock(&(philo->sh_info->mutex_c));
		sem_wait(philo->sh_info->print);
		gettimeofday(&t, 0);
		current = stamp(t.tv_sec, t.tv_usec, philo);
		printf("at %ld %dth start thinking", current, n);
		printf("                      [%d]\n", philo->state);
		sem_post(philo->sh_info->print);
		usleep(500);
	}
	pthread_mutex_unlock(&(philo->sh_info->mutex_c));
}
