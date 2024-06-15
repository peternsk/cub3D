/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_GNL.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:44:47 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 13:04:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove_gnl(char *dst, char *src, size_t len)
{
	len = ft_strlen_gnl(src);
	if (!dst || !src)
		return (0);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst >= src)
	{
		while (len > 0)
		{
			dst[len - 1] = src[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy_gnl(dst, src, len);
	}
	dst[ft_strlen_gnl(src)] = '\0';
	return (dst);
}
