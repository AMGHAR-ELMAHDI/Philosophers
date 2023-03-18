/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:20:19 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/18 16:53:32 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_create_threads(t_push *philo)
{
	philo->pheada = philo->heada;
	gettimeofday(&philo->start, NULL);
	while (philo->heada)
	{
		if (philo->heada->data % 2)
			usleep(100);
		if (pthread_create(&philo->heada->id, NULL, \
		&ft_execute_threads, philo->heada) != 0)
			ft_error("Thread Creation Error");
		pthread_detach(philo->heada->id);
		philo->heada = philo->heada->next;
		if (philo->heada == philo->pheada)
			break ;
	}
	while(1);
}

void	*ft_execute_threads(void *heada)
{
	t_list	*thr;

	thr = (t_list *)heada;
	while(1)
	{
		ft_threads_eating(thr);
		ft_threads_dying(thr);
	}
	return (0);
}

void	ft_threads_dying(t_list *thr)
{
	if(thr->last_eat >= thr->philo->time_to_die)
	{
		ft_print_status(thr, "died");
		exit(0);
	}	
}

void	ft_print_status(t_list *thr, char *str)
{
	pthread_mutex_lock(&thr->philo->print);
	usleep(10);
	printf("%lld\tms\t%d\t%s\n", get_time(thr->philo), thr->data, str);
	pthread_mutex_unlock(&thr->philo->print);
}

void	*ft_threads_eating(t_list *thr)
{
	pthread_mutex_lock(&thr->fork);
	ft_print_status(thr, "has taken a fork");
	pthread_mutex_lock(&thr->next->fork);
	ft_print_status(thr, "has taken a fork");
	ft_print_status(thr, "is eating");
	usleep(thr->philo->time_to_eat * 1000);
	pthread_mutex_unlock(&thr->fork);
	pthread_mutex_unlock(&thr->next->fork);
	ft_print_status(thr, "is sleeping");
	usleep(thr->philo->time_to_sleep * 1000);
	ft_print_status(thr, "is thinking");
	return (NULL);
}
