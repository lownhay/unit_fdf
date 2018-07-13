/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:41:58 by abulakh           #+#    #+#             */
/*   Updated: 2018/02/24 19:41:59 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_field(t_print stp, va_list ap, char **format)
{
	if (**format != '\0' && ft_strchr("di", **format))
		ft_put_di(stp, ap, format);
	else if (**format != '\0' && ft_strchr("DU", **format))
		ft_put_dubl(stp, ap, format);
	else if (**format != '\0' && ft_strchr("oxuX", **format))
		ft_put_ouxxbl(stp, ap, format);
	else if (**format == 'O')
		ft_put_obl(stp, ap, format);
	else if (**format == 'c')
		ft_put_c(stp, ap, format);
	else if (**format == 'C')
		ft_put_cbl(stp, ap, format);
	else if (**format == 's')
		ft_put_s(stp, ap, format);
	else if (**format == 'S')
		ft_put_sbl(stp, ap, format);
	else if (**format == 'p')
		ft_put_p(stp, ap, format);
	else if (**format == '%')
		ft_put_chtoto(stp, format);
	else if (**format == '\0')
		return ;
	else
		ft_else(stp, format);
}

void	ft_length_mod(t_print stp, va_list ap, char **format)
{
	if (**format == 'h' && *(*format + 1) == 'h')
		stp.hhhllljz[0] = 1;
	else if (**format == 'h' && *(*format + 1) != 'h')
		stp.hhhllljz[1] = 1;
	else if (**format == 'l' && *(*format + 1) != 'l')
		stp.hhhllljz[2] = 1;
	else if (**format == 'l' && *(*format + 1) == 'l')
		stp.hhhllljz[3] = 1;
	else if (**format == 'j')
		stp.hhhllljz[4] = 1;
	else if (**format == 'z')
		stp.hhhllljz[5] = 1;
	if (ft_strchr("hljz", **format) && (stp.hhhllljz[0] == 1 ||
		stp.hhhllljz[3] == 1))
		*format += 2;
	else if (ft_strchr("hljz", **format) && (stp.hhhllljz[1] == 1 ||
		stp.hhhllljz[2] == 1 || stp.hhhllljz[4] == 1 || stp.hhhllljz[5] == 1))
		(*format)++;
	while (**format && ft_strchr("hljz", **format))
		(*format)++;
	if (**format && ft_strchr("+-0 #", **format))
		return (ft_start_va(format, ap, stp));
	return (ft_type_field(stp, ap, format));
}

void	ft_wth_func(t_print stp, va_list ap, char **format)
{
	if (**format >= '0' && **format <= '9')
		stp.wth[0] = ft_atoi(*format);
	else if (**format == '*')
		stp.wth[0] = ft_modul(va_arg(ap, int), &stp, format);
	else if (stp.wth[0] == -1)
		stp.wth[0] = 0;
	while (**format >= '0' && **format <= '9')
		(*format)++;
	if (**format == '.')
	{
		stp.wth[1] = 1;
		(*format)++;
	}
	else if (**format == '*')
		stp.wth[0] = ft_modul(va_arg(ap, int), &stp, format);
	if (**format >= '0' && **format <= '9')
		stp.wth[2] = ft_atoi(*format);
	else if (**format == '*')
		stp.wth[2] = va_arg(ap, int);
	else if (stp.wth[1] == 1)
		stp.wth[2] = 0;
	while ((**format >= '0' && **format <= '9') || **format == '*')
		(*format)++;
	return (ft_length_mod(stp, ap, format));
}

void	ft_start_va(char **format, va_list ap, t_print stp)
{
	while (**format != '\0' && ft_strchr("+#0 -", **format))
	{
		if (**format == '+')
			stp.first[0] = 1;
		if (**format == '#')
			stp.first[1] = 1;
		if (**format == '0')
			stp.first[2] = 1;
		if (**format == ' ')
			stp.first[3] = 1;
		if (**format == '-')
			stp.first[4] = 1;
		(*format)++;
	}
	return (ft_wth_func(stp, ap, format));
}

int		ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	t_print	stp;

	g_p = 0;
	ft_baby_zero(&stp);
	str = (char *)format;
	va_start(ap, format);
	while (*str)
	{
		while (*str && *str != '%')
			ft_put_str(&str);
		if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			ft_start_va(&str, ap, stp);
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			ft_int_plus(&g_p, '%', 0);
			str += 2;
		}
	}
	va_end(ap);
	return (g_p);
}
