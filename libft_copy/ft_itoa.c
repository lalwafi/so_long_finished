/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:36:02 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/13 09:25:51 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_numbers(int ncopy)
{
	int	count;

	count = 0;
	if (ncopy < 0)
	{
		count++;
		ncopy *= -1;
	}
	if (ncopy < 9)
		count++;
	else
	{
		while (ncopy)
		{
			count++;
			ncopy = ncopy / 10;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		ncopy;

	ncopy = n;
	if (ncopy == -2147483648)
		return (ft_strdup("-2147483648"));
	i = count_numbers(ncopy);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	if (ncopy < 0)
	{
		result[0] = '-';
		ncopy *= -1;
	}
	if (ncopy == 0)
		result[i] = '0';
	while (ncopy != 0)
	{
		result[i--] = (ncopy % 10) + '0';
		ncopy /= 10;
	}
	return (result);
}
