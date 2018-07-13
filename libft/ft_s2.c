/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:24:31 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:24:33 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrwchar(wchar_t *a)
{
	if (a == NULL)
		return ;
	while (*a)
	{
		ft_putwchar_fd(*a, 1);
		a++;
	}
}

void	ft_put_s2wc3(wchar_t *a, t_print stp, char ag, int m)
{
	while (stp.wth[1] == 1 && stp.wth[2] > 0 && a != NULL && *a != '\0')
	{
		ft_putwchar_fd(*a, 1);
		(stp.wth[2])--;
		(stp.wth[0])--;
		g_p += ft_lenwchar(*a);
		a++;
	}
	if (stp.wth[1] == 0)
	{
		if (a != NULL)
		{
			ft_putstrwchar(a);
			g_p += m;
			stp.wth[0] -= m;
		}
	}
	while (stp.wth[0] > 0)
		ft_int_minus(&(stp.wth[0]), ag, 1);
}

void	ft_put_s2wc2(wchar_t *a, t_print stp, char ag, int m)
{
	if (stp.first[4] == 0)
	{
		m = ft_strlenwc2(a, stp);
		while ((stp.wth[1] == 0 && stp.wth[0] > m) ||
			(stp.wth[1] == 1 && stp.wth[0] > stp.wth[2]))
			ft_int_minus(&(stp.wth[0]), ag, 1);
		while (stp.wth[0] > m)
			ft_int_minus(&(stp.wth[0]), ag, 1);
		if (stp.wth[1] == 0 && a != NULL)
		{
			ft_putstrwchar(a);
			g_p += m;
			stp.wth[0] -= m;
		}
		while (stp.wth[1] == 1 && stp.wth[2] >= ft_lenwchar(*a)
			&& a != NULL && *a != '\0')
		{
			ft_putwchar_fd(*a, 1);
			(stp.wth[2]) -= ft_lenwchar(*a);
			g_p += ft_lenwchar(*a);
			a++;
		}
	}
	else
		ft_put_s2wc3(a, stp, ag, m);
}

void	ft_put_s2wc(wchar_t *a, t_print stp)
{
	char	ag;
	int		m;

	if (a == NULL)
	{
		a = L"(null)";
		m = 6;
	}
	else
		m = ft_strlenwc(a);
	ag = ' ';
	if (stp.first[2] == 1)
		ag = '0';
	ft_put_s2wc2(a, stp, ag, m);
}

void	ft_put_sbl(t_print stp, va_list ap, char **format)
{
	wchar_t	*a;

	a = (wchar_t *)va_arg(ap, wchar_t *);
	(*format)++;
	ft_put_s2wc(a, stp);
}
