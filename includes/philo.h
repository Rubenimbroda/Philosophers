/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:01:57 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/01/15 14:41:34 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include "structs.h"

int		is_number(char *str);
int		is_postive(char *str);
long	ft_atoi(char *str);
int		ft_strlen(char *str);
int		print_error(char *str);


#endif