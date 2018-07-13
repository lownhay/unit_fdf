/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:54:29 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/04 18:54:29 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	a = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!a)
		return (0);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	a[i] = '\0';
	return (a);
}
