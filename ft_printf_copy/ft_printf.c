/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:29:20 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/08 13:37:50 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	whatisit(va_list arguments, char format)
{
	int	counter2;

	counter2 = 0;
	if (format == 'c')
		counter2 += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		counter2 += ft_putstr(va_arg(arguments, char *));
	else if (format == 'x' || format == 'X')
		counter2 += ft_puthex(va_arg(arguments, unsigned int), format);
	else if (format == 'p')
		counter2 += ft_putptr(va_arg(arguments, void *));
	else if (format == 'd' || format == 'i')
		counter2 += ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		counter2 += ft_putunsigned(va_arg(arguments, unsigned int));
	else if (format == '%')
		counter2 += ft_putchar('%');
	return (counter2);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += whatisit(arguments, format[i + 1]);
			i++;
		}
		else
			counter += ft_putchar(format[i]);
		i++;
	}
	return (counter);
}
