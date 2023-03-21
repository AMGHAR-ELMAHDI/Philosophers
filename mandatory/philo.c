/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:38 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/21 15:11:53 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int ac, char **av)
{
	t_push	philo;

	philo.heada = NULL;
	if (ft_param_init(ac, av, &philo) == 1)
		return (0);
	if (ft_parcing(ac, av, &philo) == 1)
		return (0);
	if (ft_create_threads(&philo) == 1)
	{
		philo.i = -1;
		while (++philo.i < philo.philo_num)
		{
			if (pthread_mutex_destroy(&philo.heada->fork) != 0)
				return (1);
			philo.heada = philo.heada->next;
		}
		if (pthread_mutex_destroy(&philo.print) != 0)
			return (1);
		if (pthread_mutex_destroy(&philo.death) != 0)
			return (1);
		if (pthread_mutex_destroy(&philo.eat) != 0)
			return (1);
	}
}

int	ft_param_init(int ac, char **av, t_push *philo)
{
	if (ac < 5 || ac > 6)
		return (1);
	philo->thr_dead = 0;
	philo->thr_print = 0;
	philo->philo_num = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->time_must_eat = ft_atoi(av[5]);
	else
		philo->time_must_eat = 0;
	if (pthread_mutex_init(&philo->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->death, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->eat, NULL) != 0)
		return (1);
	return (0);
}

int	ft_parcing(int ac, char **av, t_push *philo)
{
	philo->i = 0;
	if (!ft_check_int(av + 1))
		return (1);
	if (philo->philo_num > 200 || philo->philo_num < 1)
		return (1);
	if (philo->time_to_die < 60 || philo->time_to_eat < 60
		|| philo->time_to_sleep < 60
		|| (philo->time_must_eat && philo->time_must_eat < 1))
		return (1);
	while (++philo->i <= philo->philo_num)
		ft_lstadd_back(&philo->heada, ft_lstnew(philo->i, philo));
	return (0);
}

long long	get_time(t_push *philo)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec * 1000) + (end.tv_usec / 1000))
		- ((philo->start.tv_sec * 1000) + (philo->start.tv_usec / 1000)));
}

long long	get_current_time(void)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000) + (end.tv_usec / 1000));
}
