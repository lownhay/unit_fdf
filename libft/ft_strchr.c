/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:07:04 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/26 17:07:04 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	if (a == NULL || (*a == '\0' && c != '\0'))
		return (NULL);
	while (*a)
	{
		if (*a == (char)c)
			break ;
		a++;
		if (*a == '\0' && c != '\0')
			return (NULL);
	}
	return (a);
}
