/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:25:08 by monabid           #+#    #+#             */
/*   Updated: 2022/10/16 18:45:25 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*h;
	t_list	*d;

	if (lst && del)
	{
		d = *lst;
		h = (*lst)->next;
		(*del)(d->content);
		free(*lst);
		*lst = h;
		if (h)
			ft_lstclear(lst, (*del));
	}
}
