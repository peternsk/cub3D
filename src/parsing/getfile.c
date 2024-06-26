#include "cube.h"

char    **read_fd(char *s, int len_map)
{
    char    **map;
    int      fd;
    int        i;

    i = 0;
    fd = open(s, O_RDONLY);
    if (len_map <= 0)
        return (err("Error\nEmpty file\n"), NULL);
    map = malloc((len_map + 1) * sizeof(char **));
    if (!map)
        return (NULL);
    map[i] = get_next_line(fd);
    while (map[i] != NULL)
    {
        i++;
        map[i] = get_next_line(fd);
    }
    return (map);
}


char **getfile(char *s)
{
    int     fd;
    int     len_map;

    len_map = 0;
    char    *str;
    fd = open(s, O_RDONLY);
    if (fd < 0)
        return (NULL);
    len_map = 0;
    str = get_next_line(fd);
    while (str != NULL)
    {
        free(str);
        str = NULL;
        len_map++;
        str = get_next_line(fd);
    }
    close(fd);
    return (read_fd(s, len_map));
}