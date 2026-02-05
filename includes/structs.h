/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:39:35 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/02/05 03:04:02 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <bits/pthreadtypes.h>

typedef struct s_philo t_philo;
typedef struct s_rules t_rules;

typedef struct s_philo
{
	int id;
	int eat_count;
	long last_meal;
	pthread_t thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	t_rules *rules;
} t_philo;

typedef struct s_rules
{
	int				n_philo;
	long			die;
	long			eat;
	long			sleep;
	long			think;
	int				must_eat;
	long			start_time;
	int				some_died;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_rules;

#endif