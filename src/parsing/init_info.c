#include "cube.h"

t_info_file *init_info()
{
    t_info_file *new;

    new = malloc(sizeof(t_info_file));
    if (!new)
        return (NULL);
    new->v_map = NULL;
    new->v_rgb = NULL;
    new->v_texture = NULL;
    return (new);
}