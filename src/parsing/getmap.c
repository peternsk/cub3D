#include "cube.h"

int    len_map(char **files)
{
    int y;
    int len;

    y = 0;
    len = 0;
    while (files[y])
    {
        if (wallscolors(files[y]) == false && pathtexture(files[y]) == false)
                len++;
        y++;
    } 
    return (len);
}

char    **load_map(char **file, char **map)
{
    int y;
    int i;

    y = 0;
    i = 0;
    while (file[y])
    {
        if (wallscolors(file[y]) == false && pathtexture(file[y]) == false)
        {
            map[i] = file[y];
            i++;
        }
        y++;
    } 
    return (map[i] = NULL, map);
}
char    **getmap(char **file)
{
    char    **map;
    int     len;

    if (file)
    {
        len = len_map(file);
        map = malloc (sizeof(char **) * (len + 1));
        if (!map)
            return (NULL);
        map = load_map(file, map);
        return (map);
    }
    return (NULL);
}