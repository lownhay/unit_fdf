/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ouxxbl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:27:06 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:27:07 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ouxxbl_m(int m, char *a, t_print stp, int base)
{
	if (stp.first[1] == 1 && base == 8)
		ft_int_plus(&m, '0', 1);
	else if (stp.first[1] == 1 && a[0] != '0' && base == 16)
	{
		ft_int_plus(&g_p, '0', 0);
		ft_int_plus(&g_p, 'x', 0);
	}
	else if (stp.first[1] == 1 && a[0] != '0' && base == 17)
	{
		ft_int_plus(&g_p, '0', 0);
		ft_int_plus(&g_p, 'X', 0);
	}
	while (stp.wth[1] == 1 && m < stp.wth[2])
		ft_int_plus(&m, '0', 1);
	if (!((stp.wth[2] == 0 && a[0] == '0') ||
		(stp.first[1] == 1 && a[0] == '0' && base == 8)))
	{
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
	}
}
