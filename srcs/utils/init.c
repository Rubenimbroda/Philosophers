/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:45:00 by ruben             #+#    #+#             */
/*   Updated: 2026/02/05 02:46:22 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
