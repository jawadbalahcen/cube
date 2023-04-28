/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:45:25 by monabid           #+#    #+#             */
/*   Updated: 2022/10/17 15:39:53 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfound(char *set, char c)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	char	*c;
	int		len;

	i = 0;
	len = 0;
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	while (s1[i] && ft_isfound((char *)set, s1[i]) == 1)
		i++;
	j = (int)ft_strlen(s1) - 1;
	while (j > 0 && ft_isfound((char *)set, s1[j]) == 1)
	{
		j--;
	}
	if (j > 0)
		len = j - i + 1;
	c = ft_substr(s1, i, len);
	if (c == NULL)
		return (0);
	c[len] = 0;
	return (c);
}
