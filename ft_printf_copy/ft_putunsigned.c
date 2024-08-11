/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:41:47 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/06 22:50:27 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	counternbr;

	counternbr = 0;
	if (n < 0)
	{
		counternbr += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		counternbr += ft_putnbr(n / 10);
		counternbr += ft_putchar((n % 10) + '0');
	}
	else if (n >= 0 && n <= 9)
		counternbr += ft_putchar(n + '0');
	return (counternbr);
}
