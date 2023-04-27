/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:23:23 by monabid           #+#    #+#             */
/*   Updated: 2022/10/06 21:24:05 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*c;

	i = ft_strlen(s1);
	c = (char *)malloc(i + 1);
	if (c == NULL)
		return (NULL);
	ft_strlcpy(c, s1, i + 1);
	return (c);
}
