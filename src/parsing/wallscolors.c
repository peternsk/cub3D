#include "cube.h"

bool    check_rgb(char *rgb)
{
    int i;
    int dot;

    i = 0;
    dot = 0;
    while (rgb[i] != '\0' && (ft_isdigit(rgb[i]) == 1 || rgb[i] == ' ' || rgb[i] == ','))
    {
        if (rgb[i] == 44)
            dot++;
        i++;
    }
    if (dot == 2)
        return (true);
    return (false);
}

bool    wallscolors(char *data)
{
    int     i;
    bool    still;

    i = 0;
    still = false;
    if (!data)
        return (false);
    while (data[i] != '\0')
    {
        if (ft_isupper(data[i]) == 1 && i == 0)
        {
            i++;
            if (data[i] == ' ')
            {
                i++;
                if (check_rgb(data + i) == true)
                    return (true);
            }
        }
        i++;
    }
    return (false);
}