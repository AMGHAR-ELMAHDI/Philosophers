/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:05 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/20 18:58:42 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nextlst;
	t_list	*head;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	nextlst = *lst;
	while (nextlst->next != head)
		nextlst = nextlst->next;
	nextlst->next = new;
	new->next = head;
	new->prev = nextlst;
	head->prev = new;
}

t_list	*ft_lstnew(int data, t_push *philo)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (pthread_mutex_init(&new->fork, NULL) != 0)
	{
		printf("Mutex Init Error\n");
		return (NULL);
	}
	new->philo = philo;
	new->last_eat = 0;
	new->must_eat = 0;
	new->next = new;
	new->prev = new;
	new->data = data;
	return (new);
}

long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++ ;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

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
