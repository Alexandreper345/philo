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
#include "../Libft/libft.h"

typedef pthread_mutex_t t_mtx;
typedef long long		t_time;

typedef struct s_philo
{

} t_philo;


typedef struct s_table
{
	bool	philo_die;
	int		*forks;
	int		size_philos;
	int		size_philos_eat;	
	t_philo	**philos;
	t_mtx	mutex_print;
	t_time	time_die;
	t_time	time_eat;
	t_time	time_sleep;
	t_time	init_table;
} t_table;

int	init_table(t_table **table, int argc, char **argv);

#endif