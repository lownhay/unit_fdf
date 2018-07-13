/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:58:02 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/26 13:58:03 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;
	size_t	i;

	b = (char *)s1;
	i = ft_strlen(b);
	a = malloc(sizeof(char) * i + 1);
	if (!a)
		return (NULL);
	while (*b)
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
	a -= i;
	return (a);
}
