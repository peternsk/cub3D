/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:49:47 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:49:48 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

int	throw_error(char *error, int exit_code)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Error\n%s\n", error);
	ft_printf("\033[0m");
	if (exit_code >= 0)
		exit(exit_code);
	return (1);
}

int	throw_error_detail(char *error, char *error_msg, int exit_code)
{
	printf("\033[0;31m\n");
	printf("Error\n%s\n", error);
	if (error_msg)
		printf("-> [%s]\n", error_msg);
	printf("\033[0m");
	if (exit_code >= 0)
		exit(exit_code);
	return (1);
}
