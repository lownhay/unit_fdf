/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:00:18 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 17:00:19 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_modul(int nbr, t_print *stp, char **format)
{
	if (nbr >= 0)
	{
		(*format)++;
		return (nbr);
	}
	else
	{
		(*format)++;
		stp->first[4] = 1;
		return (-nbr);
	}
}

void	ft_int_plus(int *m, char c, int flag)
{
	if (flag == 1)
		g_p++;
	ft_putchar(c);
	(*m)++;
}

void	ft_int_minus(int *m, char c, int flag)
{
	if (flag == 1)
		g_p++;
	ft_putchar(c);
	(*m)--;
}

void	ft_put_str(char **str)
{
	ft_putchar(**str);
	g_p++;
	(*str)++;
}

void	ft_baby_zero(t_print *stp)
{
	stp->first[0] = 0;
	stp->first[1] = 0;
	stp->first[2] = 0;
	stp->first[3] = 0;
	stp->first[4] = 0;
	stp->wth[0] = -1;
	stp->wth[1] = 0;
	stp->wth[2] = -1;
	stp->hhhllljz[0] = 0;
	stp->hhhllljz[1] = 0;
	stp->hhhllljz[2] = 0;
	stp->hhhllljz[3] = 0;
	stp->hhhllljz[4] = 0;
	stp->hhhllljz[5] = 0;
}
