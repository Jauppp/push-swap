/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:29:26 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/01/16 16:41:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfree(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (lst);
	while (lst)
	{
		current = lst->next;
		free(lst);
		lst = current;
	}
	lst = NULL;
	return (lst);
}
