/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:38 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/19 18:22:57 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int ac, char **av)
{
	t_push	philo;

	philo.heada = NULL;
	ft_param_init(ac, av, &philo);
	ft_parcing(ac, av, &philo);
	ft_create_threads(&philo);
}

void	ft_param_init(int ac, char **av, t_push *philo)
{
	if (ac < 5 || ac > 6)
		ft_error("Wrong Numebr of Arguments");
	philo->thr_dead = 0;
	philo->philo_num = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->time_must_eat = ft_atoi(av[5]);
	else
		philo->time_must_eat = 0;
	if (pthread_mutex_init(&philo->print, NULL) != 0)
		ft_error("Mutex Init Error");
	if (pthread_mutex_init(&philo->death, NULL) != 0)
		ft_error("Mutex Init Error");
}

void	ft_parcing(int ac, char **av, t_push *philo)
{
	philo->i = 0;
	if (!ft_check_int(av + 1))
		ft_error("Try using an integer");
	if (philo->philo_num > 200 || philo->philo_num < 1)
		ft_error("Wrong amount of Philosophers");
	if (philo->time_to_die < 60 || philo->time_to_eat < 60
		|| philo->time_to_sleep < 60
		|| (philo->time_must_eat && philo->time_must_eat < 1))
		ft_error("Time set is under 60ms");
	while (++philo->i <= philo->philo_num)
		ft_lstadd_back(&philo->heada, ft_lstnew(philo->i, philo));
}

long long	get_time(t_push *philo)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec * 1000 ) + (end.tv_usec / 1000)) -
		((philo->start.tv_sec * 1000) + (philo->start.tv_usec / 1000)));
}

long long	get_current_time()
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000 ) + (end.tv_usec / 1000));
}
