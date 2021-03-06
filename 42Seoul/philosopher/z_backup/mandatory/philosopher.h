#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>
#include <stdint.h>

#define LEFT     (n - 1 + number) % number
#define RIGHT    (n - 2 + number) % number

typedef struct s_info
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	std_sec;
	int	std_usec;
	int	cnt;
	int	end;
	int	death;
	pthread_mutex_t mutex_c;
	pthread_mutex_t *mutex_s;
	pthread_mutex_t	*mutex_m;
}t_info; //공유자원들

typedef struct s_philo
{
	int	th_num;
	int state;
	int	end;
	long former;
	pthread_t thr;
	t_info *sh_info;
}t_philo; //철학자 개개인의 속성들


void    monitoring(t_philo  *philo, int n);
void    *routine(void *data);
int 	picking(int n, t_philo *philo);
int 	eating(int n, t_philo *philo);
int		sleeping(int n, t_philo *philo);
int		thinking(int n, t_philo *philo);
void    ft_msleep(int time);
void    fork_mutex_lock(int n, t_philo *philo);
void    fork_mutex_unlock(int n, t_philo *philo);
long    stamp(long sec, long usec, t_philo *philo);
t_philo	*philo_init(int argc, char *argv[]);
t_info	*info_init(int argc, char *argv[]);
void	free_all(t_philo *philo);