/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:41:31 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:41:32 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
}

void	ft_put_c2wc(wchar_t a, t_print stp)
{
	int	len;

	len = 0;
	if (a <= 0x7F)
		len = 1;
	else if (a <= 0x7FF)
		len = 2;
	else if (a <= 0xFFFF)
		len = 3;
	else if (a <= 0x10FFFF)
		len = 4;
	if (stp.first[4] == 0)
	{
		while (stp.wth[0] > len)
			ft_int_minus(&(stp.wth[0]), ' ', 1);
		ft_putwchar_fd(a, 1);
		g_p += len;
	}
	else
	{
		ft_putwchar_fd(a, 1);
		g_p += len;
		while (stp.wth[0] > len)
			ft_int_minus(&(stp.wth[0]), ' ', 1);
	}
}

void	ft_put_c2ch(char a, t_print stp)
{
	char	ag;

	ag = ' ';
	if (stp.first[2] == 1)
		ag = '0';
	if (stp.first[4] == 0)
	{
		while (stp.wth[0] > 1)
			ft_int_minus(&(stp.wth[0]), ag, 1);
		ft_putchar(a);
		g_p++;
	}
	else
	{
		ft_putchar(a);
		g_p++;
		while (stp.wth[0] > 1)
			ft_int_minus(&(stp.wth[0]), ag, 1);
	}
}

void	ft_put_c(t_print stp, va_list ap, char **format)
{
	wchar_t	a;
	char	a2;

	a2 = 0;
	a = 0;
	if (stp.hhhllljz[0] == 1 || stp.hhhllljz[1] == 1 || stp.hhhllljz[2] == 1 ||
		stp.hhhllljz[3] == 1 || stp.hhhllljz[4] == 1 || stp.hhhllljz[5] == 1)
	{
		a = (wchar_t)va_arg(ap, wint_t);
		(*format)++;
		ft_put_c2wc(a, stp);
	}
	else
	{
		a2 = (char)va_arg(ap, unsigned int);
		(*format)++;
		ft_put_c2ch(a2, stp);
	}
}
