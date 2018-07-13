/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:36:22 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/17 17:36:23 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strfind(char **k, char chr)
{
	int		*pos;
	int		i;
	char	*str;

	i = 0;
	if (!k)
		return (0);
	pos = (int *)malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	while (k[i])
	{
		str = ft_strchr(k[i], chr);
		if (str != 0)
		{
			pos[0] = i;
			pos[1] = str - k[i];
			return (pos);
		}
		i++;
	}
	return (0);
}
