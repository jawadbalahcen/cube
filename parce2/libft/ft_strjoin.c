/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:33:27 by monabid           #+#    #+#             */
/*   Updated: 2023/03/20 17:48:07 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = 0;
	j = 0;
	c = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (0);
	if (s1 != NULL)
	{
		while (s1[i])
		{
			c[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		c[i] = s2[j];
		i++;
		j++;
	}
	c[i] = 0;
	return (c);
}
