/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sobaka.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:57:17 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/11 20:57:18 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sobaka(int n)
{
	if (n != 1)
		return ;
	else
	{
		ft_putstr("────────▄──────────────▄\n");
		ft_putstr("────────▌▒█───────────▄▀▒▌\n");
		ft_putstr("────────▌▒▒▀▄───────▄▀▒▒▒▐\n");
		ft_putstr("───────▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐\n");
		ft_putstr("─────▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐\n");
		ft_putstr("───▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀██▀▒▌\n");
		ft_putstr("──▐▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▒▌\n");
		ft_putstr("──▌▒▒▐▄█▀▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐\n");
		ft_putstr("─▐▒▒▒▒▒▒▒▒▒▒▒▌██▀▒▒▒▒▒▒▒▒▀▄▌\n");
		ft_putstr("─▌▒▀▄██▄▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌\n");
		ft_putstr("_▌▀▐▄█▄█▌▄▒▀▒▒▒▒▒▒░░░░░░▒▒▒▐\n");
		ft_putstr("▐▒▀▐▀▐▀▒▒▄▄▒▄▒▒▒▒▒░░░░░░▒▒▒▒▌\n");
		ft_putstr("▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐\n");
		ft_putstr("─▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌\n");
		ft_putstr("─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐\n");
		ft_putstr("──▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▌\n");
		ft_putstr("────▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀\n");
		ft_putstr("───▐▀▒▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀\n");
		ft_putstr("──▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀\n");
	}
}
