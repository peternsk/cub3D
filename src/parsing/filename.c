#include "cube.h"

bool    filename(char *file)
{
    int len;
    int l_c;
    char *cub;

    cub = ft_strdup(".cub\0");
    len = ft_strlen(file) - 1;
    l_c = ft_strlen(cub) - 1;
    while (len >= 0 && file[len] != '.' && l_c >= 0)
    {
        if (file[len] == cub[l_c])
        {
            len--;
            l_c--;
        }
        else
            break;
    }
    free(cub);
    if (l_c == 0)
        return (true);
    else
        return (false);
}