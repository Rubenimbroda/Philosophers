/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:01:57 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/01/16 18:39:06 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include "structs.h"
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

int		is_number(char *str);
int		is_postive(char *str);
long	ft_atoi(char *str);
int		ft_strlen(char *str);
int		print_error(char *str);
int 	parsing(char **av);
long	get_time(void);
int		init_rules(t_rules *rules, char **av, int ac);
int		init_philos(t_philo **philos, t_rules *rules);

#endif