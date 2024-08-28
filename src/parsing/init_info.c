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
    new->fake_maps = NULL;
    new->load_files = NULL;
    new->push_p = NULL;
    return (new);
}


void    free_array(char **array)
{
    int i;

    i = 0;
    if (array)
    {
        while (array[i] != NULL)
        {
            free(array[i]);
            i++;
        }
    }
    array = NULL;
}
void    free_rgb(t_rgb *data)
{
    t_rgb   *tmp;

    tmp = NULL;
    if (data)
    {
        while (data != NULL)
        {
            tmp = data;
            free(data->path);
            data = data->next;
            free(tmp);
        }
    }
    data = NULL;
}
void    free_texture(t_texture *data)
{
    t_texture   *tmp;

    tmp = NULL;
    if (data)
    {
        while (data != NULL)
        {
            tmp = data;
            free(data->path);
            data = data->next;
            free(tmp);
        }
    }
    data = NULL;
}
void free_info(t_info_file *data)
{
    if (data)
    {
        free_array(data->fake_maps);
        free_array(data->v_map);
        free_array(data->load_files);
        free_rgb(data->v_rgb);
        free_texture(data->v_texture);
        free(data->push_p);
        data->push_p = NULL;
    }
}