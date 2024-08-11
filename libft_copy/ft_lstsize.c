/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:15:20 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/19 17:17:54 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	count = 0;
	if (!lst)
		return (0);
	current = lst;
	while (current != NULL)
	{
		current = current -> next;
		count++;
	}
	return (count);
}
