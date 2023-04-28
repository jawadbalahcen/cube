/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:08 by monabid           #+#    #+#             */
/*   Updated: 2022/10/08 16:35:22 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getcount(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		l;
	int		i;
	long	j;

	j = n;
	l = getcount(j);
	i = 0;
	c = (char *)malloc(l + 1);
	if (c == NULL)
		return (NULL);
	c[l] = 0;
	if (j < 0)
		j *= -1;
	l--;
	while (l >= 0)
	{
		c[l] = j % 10 + '0';
		j = j / 10;
		l--;
	}
	if (*c == '0' && c[1])
		*c = '-';
	return (c);
}
