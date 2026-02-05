/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:56:29 by ruben             #+#    #+#             */
/*   Updated: 2026/02/05 03:04:01 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	while (!philo->rules->some_died)
		usleep(100);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
}

void	eat_philo(t_philo *philo)
{
	print_action(philo, "is eating");
	philo->last_meal = get_time();
	usleep(philo->rules->eat * 1000);
	philo->eat_count++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->n_philo == 1)
		return (handle_single_philo(philo));
	while (!philo->rules->some_died)
	{
		print_action(philo, "is thinking");
		usleep(100);
		take_forks(philo);
		eat_philo(philo);
		print_action(philo, "is sleeping");
		usleep(philo->rules->sleep * 1000);
	}
	return (NULL);
}

void	print_action(t_philo *philo, char *action)
{
	long	time;

	pthread_mutex_lock(&philo->rules->print);
	if (!philo->rules->some_died)
	{
		time = get_time() - philo->rules->start_time;
		printf("%ld %d %s\n", time, philo->id, action);
	}
	pthread_mutex_unlock(&philo->rules->print);
}
