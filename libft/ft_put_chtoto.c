/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chtoto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:51:34 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 19:51:36 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_chtoto(t_print stp, char **format)
{
	char	ag;

	(*format)++;
	ag = ' ';
	if (stp.first[2] == 1 && stp.first[4] != 1)
		ag = '0';
	if (stp.first[4] == 0)
	{
		while (stp.wth[0] > 1)
			ft_int_minus(&(stp.wth[0]), ag, 1);
		ft_putchar('%');
		g_p++;
	}
	else
	{
		ft_putchar('%');
		g_p++;
		while (stp.wth[0] > 1)
			ft_int_minus(&(stp.wth[0]), ag, 1);
	}
}

void	ft_else(t_print stp, char **format)
{
	char	ag;

	ag = ' ';
	if (stp.first[2] == 1 && stp.first[4] != 1)
		ag = '0';
	if (stp.first[4] == 0)
	{
		while (stp.wth[0] > 1)
			ft_int_minus(&(stp.wth[0]), ag, 1);
		ft_putchar(**format);
		g_p++;
	}
	else
	{
		ft_putchar(**format);
		g_p++;
		while (stp.wth[0] > 1)
			ft_int_minus(&(stp.wth[0]), ag, 1);
	}
	(*format)++;
}

int		ft_lenwchar(wchar_t a)
{
	int len;

	if (a <= 0x7F)
		len = 1;
	else if (a <= 0x7FF)
		len = 2;
	else if (a <= 0xFFFF)
		len = 3;
	else if (a <= 0x10FFFF)
		len = 4;
	else
		len = 0;
	return (len);
}

int		ft_strlenwc2(wchar_t *a, t_print stp)
{
	int	len;
	int	m;

	m = 0;
	while (*a)
	{
		len = ft_lenwchar(*a);
		m += len;
		a++;
		if (stp.wth[1] == 1 && stp.wth[2] < m + ft_lenwchar(*a))
			break ;
	}
	return (m);
}
