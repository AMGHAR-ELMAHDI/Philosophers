
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<stdio.h>
# include<unistd.h>
# include<pthread.h>
# include<math.h>
# include<stdlib.h>
# include<sys/time.h>

typedef struct s_list
{
	int				data;
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
	struct timeval 	start;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
}				t_push;

void	ft_param_init(int ac, char **av, t_push *philo);
void	ft_parcing(int ac, char **av, t_push *philo);
void	ft_error(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int data, t_push *philo);
void	ft_clear_lst(t_list **lst);
long	ft_atoi(const char *str);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_check_int(char **str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);	

#endif