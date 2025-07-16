/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:39:15 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/02/07 18:54:01 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd	*ft_lstmap(t_cmd *lst, void *(*f)(void *), void (*del)(void *))
{
	t_cmd	*new;
	t_cmd	*fl;

	fl = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->cmd), 0);
		if (!new->cmd)
			del(new->cmd);
		lst = lst->next;
		ft_lstadd_back(&fl, new);
	}
	return (fl);
}
