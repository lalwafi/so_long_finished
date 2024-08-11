/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:02:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/13 09:27:34 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		len = slen - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
