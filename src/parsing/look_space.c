#include "cube.h"

bool    look_space(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        if (map[i][0] == '\n')
            return (ft_putstr_fd("Error\nNewline in the map\n", 2), true);
        i++;
    }
    return (false);
}