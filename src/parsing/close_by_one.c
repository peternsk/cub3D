#include "cube.h"

bool    direction_y(char **map, int pos_x, int pos_y, int max_x)
{
    int     max_y;
    bool    track;

    max_y = size_len(map) - 1;
    track = true;
    if (pos_x == 0 ||  pos_x == max_x || pos_y == 0 || pos_y == max_y)
        return (err("Error\nMap is not close axe y : "), err(map[pos_y]), false);
    if (pos_x > 0 && pos_x < max_x && pos_y > 0 && pos_y < max_y)
    {
        pos_y--;
        track = looking_for_six("NSWE10", map[pos_y][pos_x]);
        pos_y++;
    }
    pos_y++;
    if (pos_x > 0 && pos_x < max_x && pos_y > 0 && pos_y <= max_y && track == true)
    {
         track  = looking_for_six("NSWE10", map[pos_y][pos_x]);
    }
    pos_y--;
    if (track)
        return (true);
    return (err("Error\nMap is not close  axe y : "), err(map[pos_y]), track);
}

bool    direction_x(char **map, int pos_x, int pos_y, int max_x)
{
    int max_y;
    bool    track;
    int i;

    max_y = size_len(map) - 1;
    i = 0;
    track = true;
    // printf("x %d | y %d \n", pos_x, pos_y);
    // printf("max_x %d | max_y %d \n", max_x, max_y);
    if (pos_x == 0 ||  pos_x == max_x || pos_y == 0 || pos_y == max_y)
        return (err("Error\nMap is not close axe x : "), err(map[pos_y]), false);
    if (pos_x > 0 && pos_x < max_x && pos_y > 0 && pos_y < max_y)
    {
        pos_x--;
        track = looking_for_six("NSWE10", map[pos_y][pos_x]);
        pos_x++;
    }
    pos_x++;
    if (pos_x > 0 && pos_x < max_x && pos_y > 0 && pos_y < max_y && track == true)
    {
        track = looking_for_six("NSWE10", map[pos_y][pos_x]);
        pos_x--;
    }
    if (track)
        return (true);
    return (err("Error\nMap is not close axe y : "), err(map[pos_y]), track);
}

bool    close_by_one(char **map)
{
    int     y;
    int     x;
    bool    m_continue;
    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == '0' || looking_for_six("NSWE", map[y][x]) == true)
            {
                m_continue = direction_x(map, x, y, ft_strlen(map[y]));
                if (m_continue == true)
                    m_continue = direction_y(map, x, y, ft_strlen(map[y]));
                if (!m_continue)
                    return (m_continue);
            }
            x++;
        }
        y++;
    }
    return (true);
}