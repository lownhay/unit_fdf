/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:39:54 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:39:55 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_obl(t_print stp, va_list ap, char **format)
{
	long int	val;
	char		*a;
	int			m;
	int			base;

	base = 8;
	val = (long int)va_arg(ap, long int);
	(*format)++;
	a = ft_itoa_base(val, base, 0);
	m = ft_strlen(a);
	if (m >= stp.wth[0])
		ft_put_ouxxbl_m(m, a, stp, base);
	else if (m < stp.wth[0])
		ft_put_ouxxbl_wd(m, a, stp, base);
	free(a);
}
