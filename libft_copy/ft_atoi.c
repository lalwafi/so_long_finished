/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:33:14 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/20 16:07:48 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if ((*str >= '0') && (*str <= '9'))
	{
		while ((*str >= '0') && (*str <= '9'))
		{
			n = n * 10 + (*str - '0');
			str++;
		}
	}
	return (sign * n);
}
