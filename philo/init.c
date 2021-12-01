/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:10:50 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/12/01 17:23:08 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_philo *data, char **av, int ac)
{
	data->thread = ft_atoi(av[1]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	data->die = ft_atoi(av[2]);
	if (ac == 6)
		data->nbeat = ft_atoi(av[5]);
}

void	ft_init2(t_ph *phi, t_philo *data, int i)
{
	phi->id = i + 1;
	phi->go = 0;
	phi->time_eat = data->eat;
	phi->time_sleep = data->sleep;
	phi->time_die = data->die;
	phi->nbeat = data->nbeat;
	phi->nbphilo = data->thread;
	phi->phdie = 0;
}

void	ft_init_tab(t_philo *data)
{
	int	i;

	i = 0;
	data->phi = malloc(sizeof(t_ph) * data->thread);
	data->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (data->thread + 1));
	while (data->thread > i)
	{
		ft_init2(&data->phi[i], data, i);
		pthread_mutex_init(&data->mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex[i], NULL);
	i = 0;
	while (data->thread > i)
	{
		data->phi[i].left = &data->mutex[i];
		if (i < data->thread - 1)
			data->phi[i].right = &data->mutex[i + 1];
		else
			data->phi[i].right = &data->mutex[0];
		data->phi[i].aff = &data->mutex[data->thread];
		i++;
	}
}

void	ft_stock(t_philo *data)
{
	int	i;

	i = 0;
	data->philo = (pthread_t *)malloc(sizeof(pthread_t) * data->thread);
	while (data->thread > i)
	{
		pthread_create(&data->philo[i], NULL, &activity, &data->phi[i]);
		i++;
	}
}
