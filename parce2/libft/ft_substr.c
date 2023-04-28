/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:18:06 by monabid           #+#    #+#             */
/*   Updated: 2022/10/16 18:15:36 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (len > i)
		len = i;
	c = (char *)ft_calloc(len + 1, 1);
	if (c == NULL)
		return (0);
	if (start <= i)
		ft_strlcpy(c, s + start, len + 1);
	return (c);
}
