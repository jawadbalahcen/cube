/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monabid <monabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:17:50 by monabid           #+#    #+#             */
/*   Updated: 2023/03/20 19:10:19 by monabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	dig_to_hex(int i)
{
	if (i <= 9)
		return (i + '0');
	else
		return (i - 10 + 'a');
}

char	hex_to_dig(char i)
{
	if (ft_isdigit(i) == 1)
		return (i - '0');
	else
		return (10 + (i - 'a'));
}

int	hex_to_int(char *hex_val)
{
	int	i;
	int	j;
	int	res;

	j = 5;
	i = 0;
	res = 0;
	while (hex_val[i])
	{
		res += hex_to_dig(hex_val[i]) * (int)pow(16 , j);
		j--;
		i++;
	}
	return (res);
}

