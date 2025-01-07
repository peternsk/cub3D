/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:51:00 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:51:01 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	if (r > 255 || g > 255 || b > 255 || a > 255)
		throw_error("Please do not exceed 255 in the colors...", 1);
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_valid_color(char *string)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (string[i])
	{
		if (string[i] == ',')
			count++;
		if (string[i] == '-')
			ft_color_error_case(1);
		if ((string[i] < '0' || string[i] > '9') && string[i] != ',')
			ft_color_error_case(1);
		i++;
	}
	if (count != 2)
		ft_color_error_case(1);
}

int	get_code(char *string, int skip)
{
	int		start;
	int		end;
	int		ret;
	char	*temp;

	start = 1;
	end = start;
	while (string[start] == ' ')
		start++;
	while (string[end] != ',' && string[end])
	{
		end++;
		if (string[end] == ',' && skip > 0)
		{
			end++;
			start = end;
			skip--;
		}
	}
	temp = ft_substr(string, start, end - start);
	ret = (int)ft_atoi(temp);
	if (ret > 255)
		ft_color_error_case(1);
	free(temp);
	return (ret);
}

/**
 * @brief  Get to the line conainting the id and return its color code
 * @note
 * @param  **strings:
 * @param  *id:
 * @retval The color code of the *id
 */
int	ft_get_color(char **strings, char *id)
{
	int		i;
	char	**colors;

	i = 0;
	while (strings[i])
	{
		if (ft_strncmp(id, strings[i], 2) == 0)
			break ;
		i++;
	}
	if (strings[i] == 0)
		ft_color_error_case(3);
	ft_valid_color(strings[i]);
	colors = ft_split_set(strings[i], " ,\t");
	i = ft_pixel(ft_atoi(colors[1]), ft_atoi(colors[2]), ft_atoi(colors[3]),
			255);
	ft_free_str_array(colors);
	return (i);
}
