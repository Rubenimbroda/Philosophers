/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:44:27 by ruben             #+#    #+#             */
/*   Updated: 2026/02/16 11:13:27 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parsing(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_number(av[i]))
			return (print_error("Error: Argument must be numbers\n"), 1);
		if (is_postive(av[i]))
			return (print_error("Error: Numbers must be positive\n"), 1);
		i++;
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	is_postive(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num < 0 || num > 2147483647)
		return (1);
	return (0);
}
