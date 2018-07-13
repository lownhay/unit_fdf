/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:43:26 by abulakh           #+#    #+#             */
/*   Updated: 2018/02/24 19:43:26 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "get_next_line.h"

typedef struct	s_print
{
	int	first[5];
	int	wth[3];
	int	hhhllljz[6];
}				t_print;

int g_p;

int				ft_strcmp(const char *s1, const char *s2);
int				ft_putnbr(intmax_t n);
int				ft_atoi(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
int				ft_strlenwc2(wchar_t *a, t_print stp);
char			*ft_itoa_base(uintmax_t num, int base, int xx);
void			ft_type_field(t_print stp, va_list ap, char **format);
void			ft_length_mod(t_print stp, va_list ap, char **format);
void			ft_wth_func(t_print stp, va_list ap, char **format);
void			ft_start_va(char **format, va_list ap, t_print stp);
int				ft_printf(const char *format, ...);
void			ft_put_str(char **str);
void			ft_baby_zero(t_print *stp);
int				ft_modul(int nbr, t_print *stp, char **format);
void			ft_int_plus(int *m, char c, int flag);
void			ft_int_minus(int *m, char c, int flag);
void			ft_put_di_m(int m, intmax_t val, t_print stp);
void			ft_put_di_wd2(int m, intmax_t val, t_print stp);
void			ft_put_di_wd(int m, intmax_t val, t_print stp);
void			ft_put_di2(intmax_t val, t_print stp);
void			ft_put_di(t_print stp, va_list ap, char **format);
void			ft_put_dubl(t_print stp, va_list ap, char **format);
void			ft_put_obl(t_print stp, va_list ap, char **format);
void			ft_put_ouxxbl_m(int m, char *a, t_print stp, int base);
void			ft_put_ouxxb2_wd3(int base, t_print *stp, char *a, int *m);
void			ft_put_ouxxbl_wd2(int m, char *a, t_print stp, int base);
void			ft_put_ouxxbl_wd(int m, char *a, t_print stp, int base);
void			ft_put_ouxxbl2(uintmax_t val, t_print stp, int base);
void			ft_put_ouxxbl(t_print stp, va_list ap, char **format);
void			ft_put_p_m(int m, char *a, t_print stp, int base);
void			ft_put_p_wd2(int m, char *a, t_print stp, int base);
void			ft_put_p_wd(int m, char *a, t_print stp, int base);
void			ft_put_p2(uintmax_t val, t_print stp, int base);
void			ft_put_p(t_print stp, va_list ap, char **format);
void			ft_put_s2ch(char *a, t_print stp);
void			ft_put_s2ch2(char *a, t_print stp, char ag, int m);
void			ft_put_s2ch3(char *a, t_print stp, char ag, int m);
void			ft_put_s2wc2(wchar_t *a, t_print stp, char ag, int m);
void			ft_put_s2wc3(wchar_t *a, t_print stp, char ag, int m);
void			ft_put_s2wc(wchar_t *a, t_print stp);
void			ft_put_s(t_print stp, va_list ap, char **format);
void			ft_put_cbl(t_print stp, va_list ap, char **format);
void			ft_put_c2wc(wchar_t a, t_print stp);
void			ft_put_c2ch(char a, t_print stp);
void			ft_else(t_print stp, char **format);
void			ft_put_c(t_print stp, va_list ap, char **format);
void			ft_putwchar_fd(wchar_t chr, int fd);
void			ft_put_sbl(t_print stp, va_list ap, char **format);
void			ft_put_chtoto(t_print stp, char **format);
int				ft_lenwchar(wchar_t a);
int				ft_strlenwc(wchar_t *a);
void			ft_putstrwchar(wchar_t *a);

#endif
