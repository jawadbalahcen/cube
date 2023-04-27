/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:53:41 by monabid           #+#    #+#             */
/*   Updated: 2022/10/16 16:12:18 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if ((char *)dst <= (char *)src)
	{
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else if (len > 0)
	{
		i = len - 1;
		while (i > 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		*((char *)dst + i) = *((char *)src + i);
	}
	return (dst);
}
