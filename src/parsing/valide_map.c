#include "cube.h"

bool look_inside(char *s, int walls, int texture)
{
    bool is;

    is = false;
    if (walls == 2 && texture == 4)
        return (true);
    else if (pathtexture(s) == false && wallscolors(s) == false && (walls != 2|| texture != 4))
    {
        if (s)
        {
            while (*s != '\0')
            {
                if (*s == '\n' || *s == 32)
                    s++;
                else
                    return (err("Error\nWrong data found!!\n"), false);
            }
        }
    }
    return (true);
}

bool    last_map(char **map)
{   
    int     i;
    int     texture;
    int     walls;
    bool    track;

    i = 0;
    texture = 0;
    walls = 0;
    track = false;
    while (map[i] != NULL)
    {
        if (pathtexture(map[i]) == true && texture <= 3)
            texture++;
        if (wallscolors(map[i]) == true && walls < 2)
            walls++;
        if (look_inside(map[i], walls, texture) == false)
            return (false);
        i++;
    }
    return (true);
}

bool    error_map(char **map)
{
    bool    is_found;
    if (!map)
        return (NULL);
    is_found = false;
    is_found = look_newline(map);
    if (!is_found)
       is_found = six_char_invalide(map);
    if (is_found)
        is_found = close_by_one(map);
    return (is_found);
}

t_info_file *valide_map(char *file)
{
    t_info_file *info;

    if (filename(file) == false)
        return (err("Error\nBad filename\n"), NULL);
    info = init_info();
    info->load_files = getfile(file);
    if (last_map(info->load_files) == false)
        return (NULL);
    info->v_rgb = two_rgb(info->load_files);
    info->v_texture = four_texture(info->load_files);
    info->fake_maps = getmap(info->load_files);
    info->v_map = removenewline(info->fake_maps);
    if (error_map(info->v_map))
    {
        info->push_p = is_player(info->v_map);
        if (info->push_p)
            return (info);
    }
    return (NULL);
}