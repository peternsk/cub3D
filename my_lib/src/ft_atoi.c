/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:45:40 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:45:41 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	minus;

	i = 0;
	number = 0;
	minus = 1;
	while (nptr[i] == ' ' || (nptr[i] > 0 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		minus *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number *= 10;
		number += (nptr[i] - 48);
		i++;
	}
	return (number * minus);
}
