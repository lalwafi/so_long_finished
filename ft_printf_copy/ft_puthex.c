/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:33:44 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/06 21:57:15 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long arg, char x)
{
	int		counterhex;
	char	*a;

	counterhex = 0;
	a = NULL;
	if (x == 'x')
		a = "0123456789abcdef";
	else if (x == 'X')
		a = "0123456789ABCDEF";
	if (arg >= 16)
		counterhex += ft_puthex((arg / 16), x);
	counterhex += ft_putchar(a[arg % 16]);
	return (counterhex);
}
