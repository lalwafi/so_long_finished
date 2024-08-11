/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:23:47 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/13 09:27:31 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;

	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i > 0)
		i--;
	return (ft_substr(s1, start, (i - start + 1)));
}
