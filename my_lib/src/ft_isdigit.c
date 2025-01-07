/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:47:07 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:47:08 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}