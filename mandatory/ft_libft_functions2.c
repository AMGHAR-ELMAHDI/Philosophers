/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:26:54 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/20 14:44:08 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_int(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_go_to_sleep(long long value)
{
	long long	current;

	current = get_current_time();
	while (get_current_time() < current + value)
		usleep(100);
}

void	ft_print_status(t_list *thr, char *str)
{
	pthread_mutex_lock(&thr->philo->print);
	printf("%lld\t%d\t%s\n", get_time(thr->philo), thr->data, str);
	if (thr->philo->thr_dead == 0)
		pthread_mutex_unlock(&thr->philo->print);
}
