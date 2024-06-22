#include "cube.h"
void    err(char *str)
{
    ft_putstr_fd(str, 2);
}
bool    looking_for_six(char *s, char x)
{
    int i;

    i = 0;
    if (s)
    {
        while (s[i] != '\0')
        {
            if (s[i] == x)
                return (true);
            i++;
        }
    }
    return (false);
}
t_player *init_player(char c, int y, int x)
{
    t_player    *p;

    p = malloc(sizeof(t_player));
    if (p)
    {
        p->pos_x = x;
        p->pos_y = y;
        if (ft_strcmp("N", &c) == true)
            p->side = nord;
        if (ft_strcmp("E", &c) == true)
            p->side = east;
        if (ft_strcmp("S", &c) == true)
            p->side = south;
        if (ft_strcmp("W", &c) == true)
            p->side = west ;
        return (p);
    }
    return (NULL);
}

t_player    *is_player(char **map)
{
   
    int y;
    int x;

    y = 0;
    x = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x])
        {
            if (looking_for_six("NSWE", map[y][x]) == true)
                return (init_player(map[y][x], y, x));
            x++;
        }
        y++;
    }
    return (err("Error\nThey is no player in the maps\n"), NULL);
}

bool    six_char_invalide(char  **map)
{
    int y;
    int x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (looking_for_six("NSWE10 \n", map[y][x]) == false)
                return (err("Error\nInvalid character : "), err(&map[y][x]), err("\n"), true);
            x++;
        }
        y++;
    }
    return (false);
}