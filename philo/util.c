/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:17:41 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/12/01 16:40:09 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	ft_errors(int ac, char **av)
{
	int	i;

	i = 1;
	if (!(ac == 5 || ac == 6))
		return (write(1, "errors\n", 7));
	while (av[i])
	{
		if (!(ft_isdigit(av[i])) && ft_atoi(av[i]) < 1)
			return (write(1, "errors2\n", 8));
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	atoi;

	i = 0;
	j = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		j = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	return (atoi * j);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (c[i] >= 48 && c[i] <= 57)
		return (1);
	return (0);
}
