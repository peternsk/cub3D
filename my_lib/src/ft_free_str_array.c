/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:39 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:46:40 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	ft_free_int_array(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_free(array[i]);
		i++;
	}
	ft_free(array);
}

void	ft_free_two(void *ptr1, void *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	ptr1 = NULL;
	ptr2 = NULL;
}

void	ft_free_three(void *ptr1, void *ptr2, void *ptr3)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	if (ptr3)
		free(ptr3);
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
}

void	ft_free_str_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
