/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_line_GNL.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:36:12 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 13:04:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_line_gnl(char *str)
{
	char	*str_wobakn;
	int		i;

	i = 0;
	str_wobakn = malloc(sizeof(char) + ft_strlen_gnl(str) + 1);
	while (str[i])
	{
		str_wobakn[i] = str[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str_wobakn[i] = '\0';
	str = ft_memmove_gnl(str, str + i, ft_strlen_gnl(str + i));
	return (str_wobakn);
}
