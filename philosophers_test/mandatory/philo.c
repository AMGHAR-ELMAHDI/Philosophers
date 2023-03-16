
#include "../philosophers.h"

int main(int ac, char **av)
{
	t_push	philo;

	philo.heada = NULL;
	ft_param_init(ac, av, &philo);
	ft_parcing(ac, av, &philo);
	ft_create_threads(&philo);
}

void	ft_param_init(int ac, char **av, t_push *philo)
{
	if(ac < 5 || ac > 6)
		ft_error("Wrong Numebr of Arguments");
	philo->philo_num =   ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if(av[5])
		philo->time_must_eat = ft_atoi(av[5]);
	else
		philo->time_must_eat = 0;
}

void	ft_parcing(int ac, char **av, t_push *philo)
{
	char	**str;
	char	*join;

	philo->i = 0;
	join = ft_strjoin(ac - 1, av + 1, " ");
	str = ft_split(join, ' ');
	if (!ft_check_int(str))
		ft_error("Try using an integer");
	if (philo->philo_num > 200 || philo->philo_num < 1)
		ft_error("Wrong amount of Philosophers");
	if (philo->time_to_die < 60 || philo->time_to_eat < 60
		|| philo->time_to_sleep < 60 
		|| (philo->time_must_eat && philo->time_must_eat < 1))
		ft_error("Time set is under 60ms");
	while (++philo->i <= philo->philo_num)
		ft_lstadd_back(&philo->heada, ft_lstnew(philo->i, philo));
	philo->i = 0;
	while (str[philo->i])
		free(str[philo->i++]);
	free(str);
	free(join);
}

void	ft_create_threads(t_push *philo)
{

}
