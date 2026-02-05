/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:12:39 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/02/05 02:46:22 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	init_rules(t_rules *rules, char **av, int ac)
{
	int	i;

	rules->n_philo = ft_atoi(av[1]);
	rules->die = ft_atoi(av[2]);
	rules->eat = ft_atoi(av[3]);
	rules->sleep = ft_atoi(av[4]);
	rules->think = 0;
	rules->must_eat = -1;
	if (ac == 6)
		rules->must_eat = ft_atoi(av[5]);
	rules->some_died = 0;
	rules->start_time = get_time();
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->n_philo);
	if (!rules->forks)
		return (print_error("Error: Malloc forks failed\n"), 1);
	if (pthread_mutex_init(&rules->print, NULL))
		return (print_error("Error: Mutex print init failed\n"), 1);
	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (print_error("Error: Mutex forks init failed\n"), 1);
		i++;
	}
	return (0);
}
