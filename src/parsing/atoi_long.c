#include "cube.h"

long long int	atoi_long(const char *str)
{
     int	        i;
	long long int	result;
    long long int	pos_neg_sign;

	i = 0;
	result = 0;
	pos_neg_sign = 1;
	if (!str)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos_neg_sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * pos_neg_sign);
}


bool    is_int(long long int nb)
{
    if (nb < 0 || nb > 255)
        return (err("Error\nNumber exceed 255 or Negative number\n"), false);
    return (true);
}

bool    is_all_nb_int(char **tab_nb)
{
    bool   track;
    int     i;

    track = true;
    i = 0;
    if (tab_nb)
    {
        while (tab_nb[i] != NULL && track == true)
        {
            track = is_int(atoi_long(tab_nb[i]));
            i++;
        }
        return (track);
    }
    return (false);
}