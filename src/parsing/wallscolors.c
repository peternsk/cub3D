#include "cube.h"

t_rgb   *new_node(char *str)
{
    t_rgb   *new;

    char    **tab;
    char    **data;

    tab = ft_split(str, ' ');
    data = ft_split(tab[1], ',');
    if (is_all_nb_int(data) == true)
    {
        new = malloc(sizeof(t_rgb));
        if (new)
        {
            new->side =  type_texture(tab[0]);
            new->one = atoi_long(data[0]);
            new->two = atoi_long(data[1]);
            new->three = atoi_long(data[2]);
            new->next = NULL;
            return (new);
        }
    }
    return (NULL);
}
void    add_rgb(t_rgb **node, char *str)
{
    t_rgb   *new;
    t_rgb   *current;
    
    new = new_node(str);
    if (new)
    {
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

t_rgb   *two_rgb(char **map)
{
    int y;
    int less;
    t_rgb   *node;

    y = 0;
    less = 0;
    node = NULL;
    while (map[y] != NULL && less < 2)
    {
        if (wallscolors(map[y]) == true)
        {
            add_rgb(&node, map[y]);
            less++;
        }
        y++;
    }
    if (less > 2)
        return (err("Error\nMore floor and ceiling\n"), NULL);
    return (node);
}

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