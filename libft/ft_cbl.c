/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:40:45 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/13 21:40:46 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_cbl(t_print stp, va_list ap, char **format)
{
	wchar_t	a;

	a = (wchar_t)va_arg(ap, wint_t);
	(*format)++;
	ft_put_c2wc(a, stp);
}
