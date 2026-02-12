/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:56:29 by ruben             #+#    #+#             */
/*   Updated: 2026/02/12 01:08:03 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*handle_single_philo(t_philo *philo)
{
	int	died;

	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->rules->death_check);
	died = philo->rules->some_died;
	pthread_mutex_unlock(&philo->rules->death_check);
	while (!died)
	{
		ft_usleep(1);
		pthread_mutex_lock(&philo->rules->death_check);
		died = philo->rules->some_died;
		pthread_mutex_unlock(&philo->rules->death_check);
	}
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
}

void	eat_philo(t_philo *philo)
{
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->rules->death_check);
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->rules->death_check);
	ft_usleep(philo->rules->eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	int		died;

	philo = (t_philo *)arg;
	if (philo->rules->n_philo == 1)
		return (handle_single_philo(philo));
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(&philo->rules->death_check);
	philo->last_meal = get_time();
	died = philo->rules->some_died;
	pthread_mutex_unlock(&philo->rules->death_check);
	while (!died)
	{
		philo_cycle(philo);
		pthread_mutex_lock(&philo->rules->death_check);
		died = philo->rules->some_died;
		pthread_mutex_unlock(&philo->rules->death_check);
	}
	return (NULL);
}

void	print_action(t_philo *philo, char *action)
{
	long	time;
	int		died;

	pthread_mutex_lock(&philo->rules->print);
	pthread_mutex_lock(&philo->rules->death_check);
	died = philo->rules->some_died;
	pthread_mutex_unlock(&philo->rules->death_check);
	if (!died || ft_strcmp(action, "died") == 0)
	{
		time = get_time() - philo->rules->start_time;
		printf("%ld %d %s\n", time, philo->id, action);
	}
	pthread_mutex_unlock(&philo->rules->print);
}
