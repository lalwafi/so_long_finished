/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:32:52 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/13 09:26:27 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!b && !len)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
