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