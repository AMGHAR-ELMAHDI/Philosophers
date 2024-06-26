/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:20:19 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/21 18:04:01 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_create_threads(t_push *philo)
{
	philo->pheada = philo->heada;
	gettimeofday(&philo->start, NULL);
	while (philo->heada)
	{
		philo->heada->last_eat = get_time(philo);
		if (pthread_create(&philo->heada->id, NULL, \
		&ft_execute_threads, philo->heada) != 0)
			return (1);
		pthread_detach(philo->heada->id);
		philo->heada = philo->heada->next;
		if (philo->heada == philo->pheada)
			break ;
	}
	while (1)
	{
		if (philo->time_must_eat != 0)
		{
			if (ft_time_must_eat(philo->heada) == 1)
				return (1);
		}
		if (ft_threads_dying(philo->heada) == 1)
			return (1);
		philo->heada = philo->heada->next;
	}
	return (0);
}

void	*ft_execute_threads(void *heada)
{
	t_list	*thr;

	thr = (t_list *)heada;
	while (thr->philo->thr_dead == 0)
	{
		if (thr->data % 2)
			usleep(200);
		if (thr->philo->philo_num > 150)
			usleep(200);
		if (ft_threads_eating(thr) == 1)
			return (NULL);
	}
	return (0);
}

int	ft_threads_eating(t_list *thr)
{
	pthread_mutex_lock(&thr->fork);
	ft_print_status(thr, "has taken a fork");
	pthread_mutex_lock(&thr->next->fork);
	ft_print_status(thr, "has taken a fork");
	pthread_mutex_lock(&thr->philo->eat);
	ft_print_status(thr, "is eating");
	thr->last_eat = get_time(thr->philo);
	thr->must_eat++;
	pthread_mutex_unlock(&thr->philo->eat);
	ft_go_to_sleep(thr->philo->time_to_eat);
	pthread_mutex_unlock(&thr->fork);
	pthread_mutex_unlock(&thr->next->fork);
	ft_print_status(thr, "is sleeping");
	ft_go_to_sleep(thr->philo->time_to_sleep);
	ft_print_status(thr, "is thinking");
	return (0);
}

int	ft_time_must_eat(t_list *thr)
{
	int	i;

	i = 0;
	while (i < thr->philo->philo_num)
	{
		if (thr->must_eat >= thr->philo->time_must_eat)
			i++;
		else
			return (0);
		thr = thr->next;
	}
	thr->philo->thr_dead = 1;
	return (1);
}

int	ft_threads_dying(t_list *thr)
{
	pthread_mutex_lock(&thr->philo->death);
	if ((get_time(thr->philo) - (thr->last_eat)) > thr->philo->time_to_die)
	{
		ft_print_status(thr, "died");
		thr->philo->thr_dead = 1;
		thr->philo->thr_print = 1;
		pthread_mutex_lock(&thr->philo->print);
		return (1);
	}
	pthread_mutex_unlock(&thr->philo->death);
	return (0);
}
