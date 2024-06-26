#include "cube.h"

bool    ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    if (s1 && s2)
    {
        while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
            i++;
    }
    if (s1[i] == s2[i])
        return (true);
    return (false);
}