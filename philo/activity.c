/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:21:03 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/12/01 17:22:31 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(t_ph *temp, int i)
{
	pthread_mutex_lock(temp->aff);
	if (i == 1)
		printf("%ld philo %d take a fork\n", get_time() - temp->start, temp->id);
	else if (i == 2)
		printf("%ld philo %d is eating\n", get_time() - temp->start, temp->id);
	else if (i == 3)
		printf("%ld philo %d is sleeping\n", get_time() - temp->start, temp->id);
	else if (i == 4)
		printf("%ld philo %d is thinking\n", get_time() - temp->start, temp->id);
	pthread_mutex_unlock(temp->aff);
}

void	ft_fork(t_ph *temp)
{
	pthread_mutex_lock(temp->left);
	ft_message(temp, 1);
	pthread_mutex_lock(temp->right);
	ft_message(temp, 1);
}

void	ft_eat(t_ph *temp)
{
	ft_message(temp, 2);
	temp->go = get_time() - temp->start;
	if (temp->nbeat)
		temp->nbeat--;
	usleep(temp->time_eat * 1000);
	pthread_mutex_unlock(temp->left);
	pthread_mutex_unlock(temp->right);
}

void	ft_sleep(t_ph *temp)
{
	ft_message(temp, 3);
	usleep(temp->time_sleep * 1000);
}

void	*activity(void *arg)
{
	t_ph	*temp;

	temp = (t_ph *)arg;
	temp->start = get_time();
	if (temp->id % 2)
		usleep(200);
	while (1)
	{
		ft_fork(temp);
		ft_eat(temp);
		ft_sleep(temp);
		ft_message(temp, 4);
	}
	return ((void *)0);
}
