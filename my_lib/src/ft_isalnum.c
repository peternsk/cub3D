/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:47 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:46:48 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
