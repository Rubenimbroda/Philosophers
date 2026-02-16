/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:45:00 by ruben             #+#    #+#             */
/*   Updated: 2026/02/16 11:14:31 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_philo *philos, t_rules *rules)
{
	int			i;

	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_create(&philos[i].thread, NULL,
				philosopher_routine, &philos[i]))
			return (print_error("Error: Thread creation failed\n"), 1);
		i++;
	}
	if (pthread_create(&rules->monitor_thread, NULL, monitor, rules))
		return (print_error("Error: Monitor thread creation failed\n"), 1);
	return (0);
}

int	check_death(t_philo *philos, t_rules *rules, int i)
{
	long	last_meal;

	pthread_mutex_lock(&rules->death_check);
	last_meal = philos[i].last_meal;
	pthread_mutex_unlock(&rules->death_check);
	if (get_time() - last_meal > rules->die)
	{
		print_action(&philos[i], "died");
		pthread_mutex_lock(&rules->death_check);
		rules->some_died = 1;
		pthread_mutex_unlock(&rules->death_check);
		return (1);
	}
	return (0);
}

int	check_all_ate(t_philo *philos, t_rules *rules)
{
	int	i;
	int	all_ate;
	int	eat_count;

	i = 0;
	all_ate = 1;
	while (i < rules->n_philo)
	{
		pthread_mutex_lock(&rules->death_check);
		eat_count = philos[i].eat_count;
		pthread_mutex_unlock(&rules->death_check);
		if (eat_count < rules->must_eat)
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
		ft_usleep(1);
	}
	return (NULL);
}

void	cleanup(t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	pthread_join(rules->monitor_thread, NULL);
	while (i < rules->n_philo)
	{
		pthread_detach(philos[i].thread);
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->death_check);
	free(rules->forks);
	free(philos);
}
