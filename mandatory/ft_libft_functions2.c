/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:26:54 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/21 15:11:05 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_go_to_sleep(long long value)
{
	long long	current;

	current = get_current_time();
	while (get_current_time() < current + value)
		usleep(100);
}

void	ft_print_status(t_list *thr, char *str)
{
	if (thr->philo->thr_print == 0)
	{
		pthread_mutex_lock(&thr->philo->print);
		printf("%lld\t%d\t%s\n", get_time(thr->philo), thr->data, str);
		if (thr->philo->thr_dead == 0)
			pthread_mutex_unlock(&thr->philo->print);
	}
}
