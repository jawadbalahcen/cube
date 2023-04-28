/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:49:33 by monabid           #+#    #+#             */
/*   Updated: 2022/10/16 18:41:49 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	i = 0;
	if (!f || !s)
		return (NULL);
	c = (char *)malloc(ft_strlen(s) + 1);
	if (c == NULL)
		return (NULL);
	while (s[i])
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	c[i] = 0;
	return (c);
}
