/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:05 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/19 18:19:58 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nextlst;
	t_list	*head;

	if  (!new)
		return ;
	if  (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	nextlst = *lst;
	while  (nextlst->next != head)
		nextlst = nextlst->next;
	nextlst->next = new;
	new->next = head;
	new->prev = nextlst;
	head->prev = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if  (!new)
		return ;
	new->next = new;
	new->prev = new;
	if  (*lst)
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	*lst = new;
}

t_list	*ft_lstnew(int data, t_push *philo)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if  (!new)
		ft_error("Malloc Error");
	if  (pthread_mutex_init(&new->fork, NULL) != 0)
		ft_error("Mutex Init Error");
	new->philo = philo;
	new->last_eat = 0;
	new->must_eat = 0;
	new->next = new;
	new->prev = new;
	new->data = data;
	return (new);
}

void	ft_clear_lst(t_list **lst)
{
	t_list	*nextlst;
	t_list	*currentlst;

	if  (!lst)
		return ;
	nextlst = *lst;
	while  (*lst)
	{
		currentlst = nextlst;
		nextlst = nextlst->next;
		free(currentlst);
		if  (nextlst == *lst)
			break ;
	}
	*lst = NULL;
}

long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while  ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++ ;
	if  (str[i] == '-' || str[i] == '+')
	{
		if  (str[i] == '-')
			sign = -1;
		i++;
	}
	while  (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ns;
	int		range;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if  (!s1 || !s2)
		return (NULL);
	range = ft_strlen (s1) + ft_strlen (s2);
	ns = (char *)malloc(sizeof(char) * (range + 1));
	if  (!ns)
		ft_error("Malloc Error");
	while  (i < ft_strlen (s1))
	{
		ns[i] = s1[i];
		i++;
	}
	while  (j < ft_strlen (s2))
	{
		ns[i + j] = s2[j];
		j++;
	}
	ns[i + j] = '\0';
	return (ns);
}

void	ft_error(char *str)
{
	printf("ERROR\n%s\n", str);
	exit(1);
}

int	ft_isdigit(int c)
{
	if  (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_int(char **str)
{
	int		i;
	int		j;

	i = 0;
	while  (str[i])
	{
		j = 0;
		while  (str[i][j])
		{
			if  (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while  (str[i])
		i++;
	return (i);
}