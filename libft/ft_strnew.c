/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:00:12 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/04 17:00:12 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*beg;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	beg = str;
	while (1)
	{
		*str = '\0';
		if (size == 0)
			break ;
		str++;
		size--;
	}
	return (beg);
}
