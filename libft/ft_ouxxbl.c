/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ouxxbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:39:45 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:39:47 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ouxxb2_wd3(int base, t_print *stp, char *a, int *m)
{
	if (stp->first[1] == 1 && a[0] != '0' && base == 8)
		ft_int_minus(&(stp->wth[0]), '0', 1);
	else if (stp->first[1] == 1 && a[0] != '0' && base == 16)
	{
		*m += 2;
		stp->wth[2] += 2;
		if (stp->first[2] == 1)
			stp->wth[2] -= 2;
		ft_int_minus(&(stp->wth[0]), '0', 1);
		ft_int_minus(&(stp->wth[0]), 'x', 1);
	}
	else if (stp->first[1] == 1 && a[0] != '0' && base == 17)
	{
		*m += 2;
		stp->wth[2] += 2;
		if (stp->first[2] == 1)
			stp->wth[2] -= 2;
		ft_int_minus(&(stp->wth[0]), '0', 1);
		ft_int_minus(&(stp->wth[0]), 'X', 1);
	}
}

void	ft_put_ouxxbl_wd2(int m, char *a, t_print stp, int base)
{
	while (stp.wth[0] > (m + stp.first[1]) && ((base != 16 && base != 17 &&
		stp.wth[0] > (stp.wth[2] + stp.first[1])) || ((stp.wth[0] > (stp.wth[2]
			+ stp.first[1] + stp.first[1]) && (base == 16 || base == 17))))
		&& (stp.first[2] == 0 || stp.wth[1] == 1))
	{
		ft_int_minus(&(stp.wth[0]), ' ', 1);
		if ((stp.first[1] == 1 && stp.wth[0] == (stp.wth[2] - 1)) ||
			(stp.wth[0] == (m + 2) && base == 16 && stp.first[1] == 1))
			break ;
	}
	if (stp.first[2] == 1 && stp.wth[1] == 0 && stp.wth[0] > stp.wth[2])
		stp.wth[2] = stp.wth[0];
	ft_put_ouxxb2_wd3(base, &stp, a, &m);
	while ((stp.wth[1] == 1 && m < stp.wth[2]) ||
		(stp.first[2] == 1 && stp.wth[1] == 0 && m < stp.wth[2]))
		ft_int_plus(&m, '0', 1);
	if (!(stp.wth[1] == 1 && stp.wth[2] == 0 && a[0] == '0'))
	{
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
	}
	else if (stp.wth[1] == 1 && stp.wth[2] == 0 && stp.wth[0] > 0 && *a == '0')
		ft_int_plus(&g_p, ' ', 0);
}

void	ft_put_ouxxbl_wd(int m, char *a, t_print stp, int base)
{
	if (stp.first[4] == 1)
	{
		if (stp.first[1] == 1 && base == 8)
			ft_int_plus(&m, '0', 1);
		else if (stp.first[1] == 1 && base == 16)
		{
			ft_int_plus(&m, '0', 1);
			ft_int_plus(&m, 'x', 1);
		}
		else if (stp.first[1] == 1 && base == 17)
		{
			ft_int_plus(&m, '0', 1);
			ft_int_plus(&m, 'X', 1);
		}
		while (stp.wth[1] == 1 && m < stp.wth[2])
			ft_int_plus(&m, '0', 1);
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
		while (m < stp.wth[0])
			ft_int_plus(&m, ' ', 1);
	}
	else
		ft_put_ouxxbl_wd2(m, a, stp, base);
}

void	ft_put_ouxxbl2(uintmax_t val, t_print stp, int base)
{
	int		m;
	char	*a;

	m = 0;
	if (base != 17)
		a = ft_itoa_base(val, base, 0);
	else
		a = ft_itoa_base(val, base - 1, 1);
	m = ft_strlen(a);
	if (m >= stp.wth[0])
		ft_put_ouxxbl_m(m, a, stp, base);
	else if (m < stp.wth[0])
		ft_put_ouxxbl_wd(m, a, stp, base);
	free(a);
}

void	ft_put_ouxxbl(t_print stp, va_list ap, char **format)
{
	uintmax_t	val;

	if (stp.hhhllljz[0] == 1)
		val = (unsigned char)va_arg(ap, int);
	else if (stp.hhhllljz[1] == 1)
		val = (unsigned short int)va_arg(ap, int);
	else if (stp.hhhllljz[2] == 1)
		val = (unsigned long int)va_arg(ap, unsigned long int);
	else if (stp.hhhllljz[3] == 1)
		val = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (stp.hhhllljz[4] == 1)
		val = (uintmax_t)va_arg(ap, uintmax_t);
	else if (stp.hhhllljz[5] == 1)
		val = (size_t)va_arg(ap, size_t);
	else
		val = (unsigned int)va_arg(ap, unsigned int);
	if (**format == 'o')
		ft_put_ouxxbl2(val, stp, 8);
	else if (**format == 'x')
		ft_put_ouxxbl2(val, stp, 16);
	else if (**format == 'X')
		ft_put_ouxxbl2(val, stp, 17);
	else if (**format == 'u')
		ft_put_ouxxbl2(val, stp, 10);
	(*format)++;
}
