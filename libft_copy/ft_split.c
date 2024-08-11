/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:00 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/20 16:08:03 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free (result[i]);
		i++;
	}
	free (result);
	return (NULL);
}

static	int	make_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (!*s)
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i - 1] != c && s[i] == c) || (s[i + 1] == '\0' && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	**make_letters(char **result, char const *s, char c, int count)
{
	int	i;
	int	counter;
	int	len;

	i = 0;
	counter = 0;
	len = 0;
	while (s[i] != '\0' && counter < count)
	{
		if (s[i] != c)
		{
			while (s[i + len] != '\0' && s[i + len] != c)
				len++;
			result[counter] = ft_substr(s, i, len);
			if (!result[counter])
				return (free_array(result));
			i += len;
			len = 0;
			counter++;
		}
		else
			i++;
	}
	result[counter] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	count = make_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	return (make_letters(result, s, c, count));
}
