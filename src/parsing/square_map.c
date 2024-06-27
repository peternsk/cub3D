#include "cube.h"

int	width(char **map)
{
	int	n2;
	int	tmp;
	int	i;

	i = 0;
	tmp = -1;
	if (map)
	{
		while (map[i] != NULL)
		{
			n2 = ft_strlen(map[i]);
			if (n2 > tmp)
				tmp = n2;
			i++;
		}
	}
	return (tmp);
}
char	*ft_change_space(char *s1, int width, char c)
{
	int		i;
	char	*new_s;
	int		size_s1;

	i = 0;
	size_s1 = ft_strlen(s1);
	new_s = malloc(sizeof(char *) * (width + 1));
	if (!new_s)
		return (NULL);
	while (i < width)
	{
		if (i < size_s1)
		{
			if (s1[i] == ' ' || s1[i] == '\n')
				new_s[i] = c;
			else
				new_s[i] = s1[i];
		}
		else
			new_s[i] = c;
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
char	**map(t_info_file *info)
{
	char	**square;
	int		i;

	i = 0;
	square = malloc(sizeof(char **) * (info->height + 1));
	if (!square)
		return (NULL);
	while (info->v_map[i])
	{
		square[i] = ft_change_space(info->v_map[i], info->width, 'v');
		i++;
	}
	square[i] = NULL;
	return (square);
}
char	**square_map(t_info_file *info)
{
	char **tmp;

	info->height = size_len(info->v_map);
	info->width = width(info->v_map);
	if (info->width == -1)
		return (NULL);
	tmp = map(info);
	return (free_sstr(info->v_map), tmp);
}