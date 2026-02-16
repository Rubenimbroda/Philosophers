/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:01:57 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/02/16 11:16:13 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include "structs.h"
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

int			is_number(char *str);
int			is_postive(char *str);
long		ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
int			print_error(char *str);
int			parsing(char **av);
long		get_time(void);
void		ft_usleep(long ms);
int			init_rules(t_rules *rules, char **av, int ac);
int			init_philos(t_philo **philos, t_rules *rules);
void		*handle_single_philo(t_philo *philo);
void		take_forks(t_philo *philo);
void		eat_philo(t_philo *philo);
void		*philosopher_routine(void *arg);
void		print_action(t_philo *philo, char *action);
int			create_threads(t_philo *philos, t_rules *rules);
int			check_death(t_philo *philos, t_rules *rules, int i);
int			check_all_ate(t_philo *philos, t_rules *rules);
void		*monitor(void *arg);
void		cleanup(t_philo *philos, t_rules *rules);
void		philo_cycle(t_philo *philo);

#endif