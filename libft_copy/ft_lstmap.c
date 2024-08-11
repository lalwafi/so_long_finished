/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:01:56 by lalwafi           #+#    #+#             */
/*   Updated: 2024/02/19 12:52:34 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*a;
	void	*temp;

	if (!lst || !del || !f)
		return (NULL);
	result = NULL;
	while (lst)
	{
		temp = f(lst->content);
		a = ft_lstnew(temp);
		if (!a)
		{
			ft_lstclear(&result, del);
			(*del)(temp);
			return (NULL);
		}
		ft_lstadd_back(&result, a);
		lst = lst->next;
	}
	return (result);
}
