/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:23:01 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 18:23:03 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_di_m(int m, intmax_t val, t_print stp)
{
	if (stp.first[0] == 1 && val >= 0)
		ft_int_plus(&g_p, '+', 0);
	if (stp.first[0] == 0 && stp.first[3] == 1 && val > 0)
		ft_int_plus(&g_p, ' ', 0);
	if (val < 0)
	{
		ft_int_plus(&g_p, '-', 0);
		val *= -1;
	}
	while (stp.wth[1] == 1 && m < stp.wth[2])
		ft_int_plus(&m, '0', 1);
	if (!(stp.wth[1] == 1 && stp.wth[2] == 0 && val == 0))
		g_p = g_p + ft_putnbr(val);
}

void	ft_put_di_wd2(int m, intmax_t val, t_print stp)
{
	while (stp.wth[0] > m && stp.wth[0] > stp.wth[2] &&
		(stp.first[2] == 0 || stp.wth[1] == 1))
	{
		ft_int_minus(&(stp.wth[0]), ' ', 1);
		if ((stp.first[0] == 1 || stp.first[3] == 1)
			&& stp.wth[0] == (stp.wth[2] - 1))
			break ;
	}
	if (stp.first[2] == 1 && stp.wth[1] == 0 && stp.wth[0] > stp.wth[2])
		stp.wth[2] = stp.wth[0];
	if (stp.first[0] == 1 && val >= 0)
		ft_int_minus(&(stp.wth[0]), '+', 1);
	if (stp.first[0] == 0 && stp.first[3] == 1 && val >= 0)
		ft_int_minus(&(stp.wth[0]), ' ', 1);
	if (val < 0)
		ft_int_minus(&(stp.wth[0]), '-', 1);
	val < 0 ? val *= -1 : 1;
	while ((stp.wth[1] == 1 && m < stp.wth[2]) ||
		(stp.first[2] == 1 && stp.wth[1] == 0 && m < stp.wth[2]))
		ft_int_plus(&m, '0', 1);
	if (!(stp.wth[2] == 0 && stp.wth[1] == 1 && val == 0))
		g_p = g_p + ft_putnbr(val);
	else
		ft_int_plus(&g_p, ' ', 0);
}

void	ft_put_di_wd(int m, intmax_t val, t_print stp)
{
	if (stp.first[0] == 1 || val < 0 || stp.first[3] == 1)
	{
		stp.wth[2]++;
		m++;
	}
	if (stp.first[4] == 1)
	{
		if (stp.first[0] == 1 && val > 0)
			ft_int_plus(&g_p, '+', 0);
		if (stp.first[0] == 0 && stp.first[3] == 1 && val > 0)
			ft_int_plus(&g_p, ' ', 0);
		if (val < 0)
		{
			ft_int_plus(&g_p, '-', 0);
			stp.first[0] = 1;
			val *= -1;
		}
		while (stp.wth[1] == 1 && m < stp.wth[2])
			ft_int_plus(&m, '0', 1);
		g_p = g_p + ft_putnbr(val);
		while (m < stp.wth[0])
			ft_int_plus(&m, ' ', 1);
	}
	else
		ft_put_di_wd2(m, val, stp);
}

void	ft_put_di2(intmax_t val, t_print stp)
{
	int			m;
	intmax_t	i;

	m = 0;
	i = val < 0 ? -val : val;
	while (i != 0)
	{
		i /= 10;
		m++;
	}
	if (val == 0)
		m = 1;
	if (m >= stp.wth[0])
		ft_put_di_m(m, val, stp);
	else if (m < stp.wth[0])
		ft_put_di_wd(m, val, stp);
}

void	ft_put_di(t_print stp, va_list ap, char **format)
{
	intmax_t	val;

	(*format)++;
	if (stp.hhhllljz[0] == 1)
		val = (signed char)va_arg(ap, int);
	else if (stp.hhhllljz[1] == 1)
		val = (short int)va_arg(ap, int);
	else if (stp.hhhllljz[2] == 1)
		val = (long int)va_arg(ap, long int);
	else if (stp.hhhllljz[3] == 1)
		val = (long long int)va_arg(ap, long long int);
	else if (stp.hhhllljz[4] == 1)
		val = (intmax_t)va_arg(ap, intmax_t);
	else if (stp.hhhllljz[5] == 1)
		val = (size_t)va_arg(ap, size_t);
	else
		val = (int)va_arg(ap, int);
	ft_put_di2(val, stp);
}
