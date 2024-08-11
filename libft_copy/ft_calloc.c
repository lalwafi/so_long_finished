/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:47:38 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/13 09:19:10 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count && size && (count > (SIZE_MAX / size)))
		return (NULL);
	a = malloc(size * count);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (size * count));
	return (a);
}
