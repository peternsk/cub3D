/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:45:46 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:45:47 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

/* transforme une chaine de caractère pointé par "str" en valeur numérique    */
/* dans une variable type long integer. On avance dans la chaine de caractère */
/* tant qu'il y à des espaces ou tabulations. Ensuite on change la valeur de  */
/* "sign" à -1 si le premier caractère est un tiret. On avance dans la chaine */
/* tant que les caractère se trouve entre 0 et 9. On commence avec une valeur */
/* de retour de 0 alors la premiere boucle on effectue le calcuc (0 x 10) donc*/
/* on additionne 0 à la première valeur et les suivantes se feront multiplier */
/* par 10 pour se déplacer d'une dizaine supplémentaire à chaque caractère.   */
/* on retoure ensuite la variable "ret" si la variable "sign" est toujours à 1*/
/* sinon on retourne la variable "ret" multiplier par "sign" qui est rendu à  */
/* -1 pour rendre la valeur du long int négative.							  */
long int	ft_atol(const char *str)
{
	unsigned int	i;
	long int		ret;
	long int		sign;

	i = 0;
	sign = 1;
	ret = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		ret = (str[i++] - '0') + (ret * 10);
	if (sign == 1)
		return (ret);
	return (ret * sign);
}
