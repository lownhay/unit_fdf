/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:40:32 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:40:32 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_s2ch3(char *a, t_print stp, char ag, int m)
{
	while (stp.wth[1] == 1 && stp.wth[2] > 0 && a != NULL && *a != '\0')
	{
		ft_putchar(*a);
		(stp.wth[2])--;
		(stp.wth[0])--;
		a++;
		g_p++;
	}
	if (stp.wth[1] == 0)
	{
		if (a != NULL)
		{
			ft_putstr(a);
			g_p += m;
			stp.wth[0] -= m;
		}
	}
	while (stp.wth[0] > 0)
		ft_int_minus(&(stp.wth[0]), ag, 1);
}

void	ft_put_s2ch2(char *a, t_print stp, char ag, int m)
{
	if (stp.first[4] == 0)
	{
		while (stp.wth[0] > m || (stp.wth[1] == 1 &&
			stp.wth[0] > stp.wth[2] && stp.wth[2] >= 0))
			ft_int_minus(&(stp.wth[0]), ag, 1);
		if ((stp.wth[1] == 0 || stp.wth[2] < 0) && a != NULL)
		{
			ft_putstr(a);
			g_p += m;
			stp.wth[0] -= m;
		}
		while (stp.wth[1] == 1 && stp.wth[2] > 0 && a != NULL && *a != '\0')
		{
			ft_int_minus(&(stp.wth[2]), *a, 1);
			a++;
		}
	}
	else
		ft_put_s2ch3(a, stp, ag, m);
}

void	ft_put_s2ch(char *a, t_print stp)
{
	char	ag;
	int		m;
	int		k;

	k = 0;
	if (a == NULL)
	{
		a = ft_strdup("(null)");
		m = 6;
		k = 1;
	}
	else
		m = ft_strlen(a);
	ag = ' ';
	if (stp.first[2] == 1 && stp.first[4] != 1)
		ag = '0';
	ft_put_s2ch2(a, stp, ag, m);
	if (k == 1)
		free(a);
}

int		ft_strlenwc(wchar_t *a)
{
	int	len;
	int	m;

	m = 0;
	while (*a)
	{
		if (*a <= 0x7F)
			len = 1;
		else if (*a <= 0x7FF)
			len = 2;
		else if (*a <= 0xFFFF)
			len = 3;
		else if (*a <= 0x10FFFF)
			len = 4;
		else
			len = 0;
		m += len;
		a++;
	}
	return (m);
}

void	ft_put_s(t_print stp, va_list ap, char **format)
{
	wchar_t	*a;
	char	*a2;

	a2 = NULL;
	a = NULL;
	if (stp.hhhllljz[0] == 1 || stp.hhhllljz[1] == 1 || stp.hhhllljz[2] == 1
		|| stp.hhhllljz[3] == 1 || stp.hhhllljz[4] == 1 || stp.hhhllljz[5] == 1)
	{
		a = (wchar_t *)va_arg(ap, wchar_t *);
		(*format)++;
		ft_put_s2wc(a, stp);
	}
	else
	{
		a2 = (char *)va_arg(ap, char *);
		(*format)++;
		ft_put_s2ch(a2, stp);
	}
}
