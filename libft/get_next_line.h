/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:44:04 by abulakh           #+#    #+#             */
/*   Updated: 2018/01/20 15:44:05 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int				get_next_line(const int fd, char **line);

#endif
