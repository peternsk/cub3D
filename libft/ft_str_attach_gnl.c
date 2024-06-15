/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_attach_GNL.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:37:00 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 13:05:12 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_attach_gnl(char *base_str, char *add_str)
{
	char	*new_str;
	int		len;

	len = (ft_strlen_gnl(base_str) + ft_strlen_gnl(add_str));
	new_str = (char *)malloc(len * sizeof(char) + 1);
	if (!new_str)
		return (0);
	len = 0;
	if (base_str != NULL)
	{
		while (base_str[len])
		{
			new_str[len] = base_str[len];
			len++;
		}
		free(base_str);
	}
	while (*add_str)
	{
		new_str[len] = *add_str;
		len++;
		add_str++;
	}
	new_str[len] = '\0';
	return (new_str);
}
