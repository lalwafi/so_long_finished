/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:00:45 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/06 22:40:45 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		counterstr;

	i = 0;
	counterstr = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
		counterstr += write(1, &s[i++], 1);
	return (counterstr);
}
