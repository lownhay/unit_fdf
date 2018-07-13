/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:41:06 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:41:07 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_p_m(int m, char *a, t_print stp, int base)
{
	if (stp.first[1] == 1 && base == 16)
	{
		ft_int_plus(&m, '0', 1);
		ft_int_plus(&m, 'x', 1);
	}
	while (stp.wth[1] == 1 && m <= stp.wth[2] + 1)
		ft_int_plus(&m, '0', 1);
	if (!((stp.wth[2] == 0 && a[0] == '0') ||
		(stp.first[1] == 1 && a[0] == '0' && base == 8)))
	{
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
	}
}

void	ft_put_p_wd2(int m, char *a, t_print stp, int base)
{
	while (stp.wth[0] > (m + stp.first[1]) && stp.wth[0] > (stp.wth[2] +
		stp.first[1] + stp.first[1]) && (stp.first[2] == 0 || stp.wth[1] == 1))
	{
		ft_int_minus(&(stp.wth[0]), ' ', 1);
		if ((stp.first[1] == 1 && stp.wth[0] == (stp.wth[2] - 1)) ||
			(stp.wth[0] == (m + 2) && stp.first[1] == 1))
			break ;
	}
	if (stp.first[1] == 1 && base == 16)
	{
		m += 2;
		stp.wth[2] += 2;
		stp.first[2] == 1 ? stp.wth[2] -= 2 : 1;
		ft_int_minus(&(stp.wth[0]), '0', 1);
		ft_int_minus(&(stp.wth[0]), 'x', 1);
	}
	while ((stp.wth[1] == 1 && m <= stp.wth[2]) ||
		(stp.first[2] == 1 && stp.wth[1] == 0 && m <= stp.wth[0] + 1))
		ft_int_plus(&m, '0', 1);
	if (!(stp.wth[1] == 1 && stp.wth[2] == 0 && a[0] == '0'))
		g_p = g_p + ft_strlen(a);
	if (!(stp.wth[1] == 1 && stp.wth[2] == 0 && a[0] == '0'))
		ft_putstr(a);
	else if (stp.wth[1] == 1 && stp.wth[2] == 0 && stp.wth[0] > 0 && *a == '0')
		ft_int_plus(&g_p, ' ', 0);
}

void	ft_put_p_wd(int m, char *a, t_print stp, int base)
{
	if (stp.first[4] == 1)
	{
		if (stp.first[1] == 1 && base == 16)
		{
			ft_int_plus(&m, '0', 1);
			ft_int_plus(&m, 'x', 1);
		}
		while (stp.wth[1] == 1 && m < stp.wth[2])
			ft_int_plus(&m, '0', 1);
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
		while (m < stp.wth[0])
			ft_int_plus(&m, ' ', 1);
	}
	else
		ft_put_p_wd2(m, a, stp, base);
}

void	ft_put_p2(uintmax_t val, t_print stp, int base)
{
	int		m;
	char	*a;

	a = ft_itoa_base(val, base, 0);
	m = ft_strlen(a);
	if (m >= stp.wth[0])
		ft_put_p_m(m, a, stp, base);
	else if (m < stp.wth[0])
		ft_put_p_wd(m, a, stp, base);
	free(a);
}

void	ft_put_p(t_print stp, va_list ap, char **format)
{
	unsigned long long	val;

	stp.first[1] = 1;
	val = (unsigned long long)va_arg(ap, unsigned long long);
	ft_put_p2(val, stp, 16);
	(*format)++;
}
