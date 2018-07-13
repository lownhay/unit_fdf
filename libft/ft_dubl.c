/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dubl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:40:02 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:40:02 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_dubl(t_print stp, va_list ap, char **format)
{
	intmax_t	val;
	uintmax_t	val2;
	int			m;
	intmax_t	i;

	m = 0;
	if (**format == 'D')
	{
		val = (long int)va_arg(ap, long int);
		i = val < 0 ? -val : val;
		while (i != 0)
		{
			i /= 10;
			m++;
		}
		val == 0 ? m = 1 : 1;
		(*format)++;
		m >= stp.wth[0] ? ft_put_di_m(m, val, stp) : ft_put_di_wd(m, val, stp);
	}
	else
	{
		(*format)++;
		val2 = (unsigned long int)va_arg(ap, unsigned long int);
		ft_put_ouxxbl2(val2, stp, 10);
	}
}
