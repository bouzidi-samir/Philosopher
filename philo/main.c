/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:14:01 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/12/01 16:15:08 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	data;

	if (ft_errors(ac, av))
		return (1);
	ft_init(&data, av, ac);
	ft_init_tab(&data);
	ft_stock(&data);
	usleep(100);
	ft_init_death(&data);
	free(data.philo);
	free(data.phi);
	free(data.mutex);
	return (0);
}
