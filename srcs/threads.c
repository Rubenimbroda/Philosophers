/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:45:00 by ruben             #+#    #+#             */
/*   Updated: 2026/02/05 03:04:07 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_philo *philos, t_rules *rules)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]))
			return (print_error("Error: Thread creation failed\n"), 1);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor, rules))
		return (print_error("Error: Monitor thread creation failed\n"), 1);
	return (0);
}

int	check_death(t_philo *philos, t_rules *rules, int i)
{
	if (get_time() - philos[i].last_meal > rules->die)
	{
		print_action(&philos[i], "died");
		rules->some_died = 1;
		return (1);
	}
	return (0);
}

int	check_all_ate(t_philo *philos, t_rules *rules)
{
	int	i;
	int	all_ate;

	i = 0;
	all_ate = 1;
	while (i < rules->n_philo)
	{
		if (philos[i].eat_count < rules->must_eat)
			all_ate = 0;
		i++;
	}
	return (all_ate);
}

void	*monitor(void *arg)
{
	t_rules	*rules;
	t_philo	*philos;
	int		i;

	rules = (t_rules *)arg;
	philos = rules->philos;
	while (!rules->some_died)
	{
		i = 0;
		while (i < rules->n_philo)
		{
			if (check_death(philos, rules, i))
				return (NULL);
			i++;
		}
		if (rules->must_eat > 0 && check_all_ate(philos, rules))
		{
			rules->some_died = 1;
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

void	cleanup(t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print);
	free(rules->forks);
	free(philos);
}
