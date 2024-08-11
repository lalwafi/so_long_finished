/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:16:19 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/06 21:57:19 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *arg)
{
	int	counterptr;

	counterptr = 0;
	counterptr += ft_putstr("0x");
	counterptr += ft_puthex((unsigned long)arg, 'x');
	return (counterptr);
}
