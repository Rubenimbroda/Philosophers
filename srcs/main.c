/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:01:32 by rnuno-im          #+#    #+#             */
/*   Updated: 2026/02/04 01:06:51 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
	t_rules rules;
	t_philo *philos;

	if (ac < 5 || ac > 6)
		return (print_error("Error invalid number of arguments\n"), 1);
	if (parsing(av))
		return (print_error("Error in arguments\n"), 1);
	if (init_rules(&rules, av, ac) != 0 || init_philos(&philos, &rules) != 0)
		return (print_error("Error initializing simulation\n"), 1);
	if (create_threads(philos, &rules) != 0)
		return (cleanup(philos, &rules), 1);
	cleanup(philos, &rules);
	return (0);
}
