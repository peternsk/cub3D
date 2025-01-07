/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:47:53 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:47:54 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../mylib.h"

int	ft_print_string(va_list vl, char c)
{
	int	i;

	i = 0;
	if (c == '%')
		i = ft_printchar('%', 1);
	else if (c == 'd' || c == 'i')
		i = ft_printnbr(va_arg(vl, int));
	else if (c == 'c')
		i = ft_printchar(va_arg(vl, int), 1);
	else if (c == 's')
		i = ft_printstr(va_arg(vl, char *), 1);
	else if (c == 'x' || c == 'X')
		i = ft_puthexadecimal(va_arg(vl, unsigned int), c);
	else if (c == 'u')
		i = ft_print_u_nbr(va_arg(vl, int));
	else if (c == 'p')
		i = ft_address2(va_arg(vl, unsigned long long));
	return (i);
}

// %[flags][width][.precision][length]specifier
int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	vl;

	va_start(vl, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_print_string(vl, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(vl);
	return (counter);
}
