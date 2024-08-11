/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:00:47 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/19 13:09:33 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (0 < i)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	return (dst);
}
