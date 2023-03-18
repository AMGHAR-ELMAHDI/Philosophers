/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:53 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/18 18:52:38 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<stdio.h>
# include<unistd.h>
# include<pthread.h>
# include<math.h>
# include<stdlib.h>
# include<sys/time.h>
#include <string.h>

typedef struct s_list
{
	int				data;
	long long		last_eat;
	struct s_list	*next;
	struct s_list	*prev;
	pthread_mutex_t	fork;
	pthread_t		id;
	struct s_push	*philo;
}				t_list;

typedef struct s_push
{
	t_list			*heada;
	t_list			*pheada;
	int				i;
	long long		current_time;
	struct timeval	start;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
}				t_push;

void		ft_param_init(int ac, char **av, t_push *philo);
void		ft_parcing(int ac, char **av, t_push *philo);
void		ft_error(char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstnew(int data, t_push *philo);
void		ft_clear_lst(t_list **lst);
long		ft_atoi(const char *str);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_isdigit(int c);
int			ft_check_int(char **str);
char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
long long	get_time(t_push *philo);
void		*ft_execute_threads(void *heada);
void		ft_thread_join(t_push *philo);
void		*ft_threads_eating(t_list *thr);
void		ft_create_threads(t_push *philo);
void	ft_print_status(t_list *thr, char *str);
void	ft_threads_dying(t_list *thr);

#endif