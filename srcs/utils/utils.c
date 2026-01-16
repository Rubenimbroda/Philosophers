/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:12:39 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/01/16 18:35:22 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parsing(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
		{
			print_error("Error: Arguments must be numbers\n");
			return (1);
		}
		if (!is_postive(av[i]))
		{
			print_error("Error: Arguments mus be positive numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}

long	get_time(void)
{
	struct	timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	init_rules(t_rules *rules, char **av, int ac)
{
	rules->n_philo = ft_atoi(av[i]);
	rules->die = ft_atoi(av[2]);
	rules->eat = ft_atoi(av[3]);
	rules->sleep = ft_atoi (av[4]);
	rules->think = 0;
	rules->must_eat = -1;
	if (ac == 6)
		rules->must_eat = ft_atoi(av[5]);
	rules->some_died = 0;
	rules->start_time = get_time();
	if (pthread_mutex_init(&rules->print, NULL))
		return (print_error("Error: Mutex print init failed\n"), 1);
	if (pthread_mutex_init(&rules->forks, NULL))
		return (print_error("Error: Mutex forks init failed\n"), 1);
	return (0);
}

int	init_philos(t_philo **philos, t_rules *rules)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * rules->n_philo);
	if (!*philos)
		return (print_error("Error: Malloc philos failed\n"), 1);
	i = 0;
	while (i < rules->n_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_count = 0;
		(*philos)[i].last_meal = rules->start_time;
		(*philos)[i].left_fork = &rules->forks;
		(*philos)[i].right_fork = &rules->forks;
		(*philos)[i].rules = rules;
		i++;
	}
	return (0);
}