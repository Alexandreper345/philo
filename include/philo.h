#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>

typedef pthread_mutex_t t_mtx;
typedef long long		t_time;

typedef	enum s_status 
{
	EATING,
	THINKING,
	DEAD,
	FULL
} t_status;

typedef struct s_philo
{
	pthread_t	id_thread;
	int			id;
	int			eating;
	t_status	status;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	t_mtx		*fork_left;
	t_mtx		*fork_right;
} t_philo;

typedef struct s_table
{
	bool		philo_die;
	int			forks;
	int			count_philos;
	int			size_philos_eat;
	t_philo		**philos;
	t_mtx		print_mutex;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	t_time		init_table;
} t_table;

t_table	*init_table(t_table **table, int argc, char **argv);
int		isnumeric(char *value);
int		ft_atoi(const char *nptr);
void	*philo_routine(void	*ptr);
t_mtx	*create_array_mutex(t_table *table);

#endif