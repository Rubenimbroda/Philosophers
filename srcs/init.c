/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:45:00 by ruben             #+#    #+#             */
/*   Updated: 2026/02/12 00:24:29 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_philo **philos, t_rules *rules)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * rules->n_philo);
	if (!*philos)
		return (print_error("Error: Malloc philos failed\n"), 1);
	rules->philos = *philos;
	i = 0;
	while (i < rules->n_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_count = 0;
		(*philos)[i].last_meal = rules->start_time;
		(*philos)[i].left_fork = &rules->forks[i];
		(*philos)[i].right_fork = &rules->forks[(i + 1) % rules->n_philo];
		(*philos)[i].rules = rules;
		i++;
	}
	return (0);
}

static int	init_mutexes(t_rules *rules)
{
	int	i;

	if (pthread_mutex_init(&rules->print, NULL))
		return (print_error("Error: Mutex print init failed\n"), 1);
	if (pthread_mutex_init(&rules->death_check, NULL))
		return (print_error("Error: Mutex death_check init failed\n"), 1);
	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (print_error("Error: Mutex forks init failed\n"), 1);
		i++;
	}
	return (0);
}

int	init_rules(t_rules *rules, char **av, int ac)
{
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
	return (init_mutexes(rules));
}
