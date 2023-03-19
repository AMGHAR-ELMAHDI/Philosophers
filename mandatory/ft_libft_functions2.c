/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:26:54 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/19 19:24:24 by eamghar          ###   ########.fr       */
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
	return (1);
}

void	ft_go_to_sleep(long long value)
{
	long long	current;

	current = get_current_time();
	while (get_current_time() < current + value)
		usleep(100);
}
