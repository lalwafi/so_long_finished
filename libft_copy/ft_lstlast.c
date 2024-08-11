/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:27:56 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/05 20:00:04 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (!lst)
		return (NULL);
	i = ft_lstsize(lst);
	while (i > 1)
	{
		lst = lst -> next;
		i--;
	}
	return (lst);
}
