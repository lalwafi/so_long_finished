/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:35:39 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/02 23:05:53 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_for_gnl(char *line, int c)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	if (c == 0)
		return (NULL);
	while (line[i])
	{
		if (line[i] == (char)c)
			return (&line[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_for_gnl(char *buffer, char *line)
{
	size_t	i;
	size_t	j;
	char	*newb;
	int		len;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	len = ft_strlen_for_gnl(buffer) + ft_strlen_for_gnl(line);
	newb = malloc(sizeof(char) * (len + 1));
	if (!newb)
		return (NULL);
	while (buffer && buffer[i] != '\0')
	{
		newb[i] = buffer[i];
		i++;
	}
	while (line[j])
		newb[i++] = line[j++];
	newb[i] = '\0';
	if (buffer)
		free(buffer);
	return (newb);
}

int	ft_strlen_for_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
