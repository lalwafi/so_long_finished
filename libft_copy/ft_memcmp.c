/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:52:39 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/19 17:27:39 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break ;
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
