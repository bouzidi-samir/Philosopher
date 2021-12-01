/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:16:00 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/12/01 17:22:17 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				eat;
	int				sleep;
	int				die;
	int				thread;
	int				fork;
	int				nbeat;
	pthread_mutex_t	*mutex;
	pthread_t		*philo;
	struct s_ph		*phi;
}	t_philo;

typedef struct s_ph
{
	int				phdie;
	int				id;
	long int		start;
	long int		go;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nbeat;
	int				nbphilo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*aff;
}	t_ph;

int			ft_atoi(const char *str);
int			ft_isdigit(char *c);
int			ft_errors(int ac, char **av);
long int	get_time(void);
void		ft_stock(t_philo *data);
void		ft_init(t_philo *data, char **av, int ac);
void		ft_init2(t_ph *phi, t_philo *data, int i);
void		ft_init_tab(t_philo *data);
void		ft_message(t_ph *temp, int i);
void		ft_fork(t_ph *temp);
void		ft_eat(t_ph *temp);
void		ft_sleep(t_ph *temp);
void		*activity(void *arg);
void		ft_init_death(t_philo *death);
#endif
