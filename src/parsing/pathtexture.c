#include "cube.h"

int type_texture(char   *str)
{
    char    **cm;
    
    cm = ft_split(str, ' ');
    if (ft_strcmp(cm[0], "NO"))
        return (free_sstr(cm), nord);
    if (ft_strcmp(cm[0], "SO"))
        return (free_sstr(cm),south);
    if (ft_strcmp(cm[0], "WE"))
        return (free_sstr(cm),west);
    if (ft_strcmp(cm[0], "EA"))
        return (free_sstr(cm),east);
    if (ft_strcmp(cm[0], "F"))
        return (free_sstr(cm),_floor);
    return (free_sstr(cm),ceiling);
}

void    add_texutre(t_texture **node, char *str)
{
    t_texture   *new;
    t_texture   *current;
    char        **data;
    
    data = ft_split(str, ' ');
    new = malloc(sizeof(t_texture));
    if (new)
    {
        new->side = type_texture(data[0]);
        new->path = data[1];
        new->next = NULL;
        if (!node || !*node)
        {
            *node = new;
            return ;
        }
        current = *node;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

}

t_texture *four_texture(char   **file)
{
    t_texture *four_texture;
    int        less;
    int        i;

    i = 0;
    less = 0;
    four_texture = NULL;
    while (file[i] != NULL && less < 5)
    {
        if (pathtexture(file[i]) == true)
        {
            less++;
            add_texutre(&four_texture, file[i]);
        }
        i++;
    }
    if (less > 4)
        return (err("Error\nMore thant four texture in the file\n"), NULL);
    return (four_texture);
}


bool pathtexture(char *data)
{
    int     i;
    bool    still;

    i = 0;
    still = false;
      if (!data)
        return (false);
    while (data[i] != '\0')
    {
        if (still == true && i == 1)
        {
            i++;
            if (data[i] == ' ')
                return (true);
        }
        if (ft_isupper(data[i])  == 1)
            still = true;
        else
            still = false;
        i++;
    }
    return (false);
}
