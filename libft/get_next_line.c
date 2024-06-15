/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:46:40 by peternsaka        #+#    #+#             */
/*   Updated: 2023/10/16 13:04:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*str_stat;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_char;

	read_char = read(fd, buffer, BUFFER_SIZE);
	while (read_char > 0)
	{
		buffer[read_char] = '\0';
		str_stat = ft_str_attach_gnl(str_stat, buffer);
		if (ft_chr_bakn_gnl(buffer, '\n') == 1)
			break ;
		read_char = read(fd, buffer, BUFFER_SIZE);
	}
	if ((read_char == -1) || (read_char <= 0 && ft_strlen_gnl(str_stat) == 0))
	{
		if (str_stat)
		{
			free(str_stat);
			str_stat = NULL;
		}
		return (NULL);
	}
	return (ft_new_line_gnl(str_stat));
}
