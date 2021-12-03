/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:23:16 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/12/01 16:25:39 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*make_death(void *death)
{	
	int		i;
	t_ph	*temp;
	int		j;

	temp = (t_ph *)death;
	j = temp[0].nbphilo;
	while (1)
	{
		usleep(2000);
		i = 0;
		while (i < j)
		{
			if (get_time() - temp[i].start >= temp[i].go + temp[i].time_die)
			{
				pthread_mutex_lock(temp[i].aff);
				temp[i].phdie = 1;
				printf("%ld philo %d died\n", get_time()
					- temp[i].start, temp[i].id);
				return ((void *)0);
			}
			i++;
		}
	}
}

int	ft_lastmeal(t_philo *data)
{
	int	i;

	i = 0;
	if (!data->nbeat)
		return (0);
	while (i < data->thread)
	{
		if (data->phi[i].nbeat > 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_death(t_philo *data, pthread_t check)
{	
	int	i;

	i = 0;
	while (1)
	{
		usleep(3000);
		if (data->phi[i].phdie == 1)
		{
			pthread_detach(check);
			return (1);
		}
		if (ft_lastmeal(data))
		{
			pthread_mutex_lock(data->phi[i].aff);
			return (1);
		}
		if (i + 1 == data->thread)
		{
			i = -1;
			usleep(200);
		}
		i++;
	}
}

void	ft_init_death(t_philo *death)
{
	pthread_t		check;

	pthread_create(&check, NULL, &make_death, death->phi);
	if (check_death(death, check))
		return ;
}
