/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:38:09 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/08 17:38:10 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_helper(int m, intmax_t i, unsigned long long int k, int *p)
{
	unsigned long long int	l;
	char					a;

	if (i < 0)
		l = -i;
	else
		l = i;
	k /= 10;
	while (m > 0)
	{
		a = (l / k) + '0';
		l = l % k;
		k /= 10;
		m--;
		(*p)++;
		ft_putchar(a);
	}
}

int			ft_putnbr(intmax_t n)
{
	intmax_t				i;
	unsigned long long int	k;
	int						m;
	int						p;

	k = 1;
	i = n;
	m = 0;
	p = 0;
	if (i == 0)
	{
		p++;
		ft_putchar('0');
	}
	while (i != 0)
	{
		i /= 10;
		k *= 10;
		m++;
	}
	ft_helper(m, n, k, &p);
	return (p);
}
