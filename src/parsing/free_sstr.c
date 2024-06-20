#include "cube.h"

void    free_sstr(char **s)
{
    int i;

    i = 0;
    if (s[i])
    {
        free(s[i]);
        s[i] = NULL;
        i++;
    }
    free(s);
    s = NULL;
}