/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:49:18 by abulakh           #+#    #+#             */
/*   Updated: 2018/04/19 18:49:19 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_gnl_2(char **line, char **date)
{
	char	*a;

	if (*date == NULL && **date == '\0')
		return (0);
	a = ft_strchr(*date, '\n');
	if (a == NULL)
	{
		*line = ft_strdup(*date);
		free(*date);
		*date = NULL;
		return (1);
	}
	else
	{
		*line = ft_strsub(*date, 0, a - *date);
		a++;
		a = ft_strdup(a);
		free(*date);
		*date = a;
		return (1);
	}
}

static int	ft_gnl_firsttype(char **line, char **str, char **date, char **a)
{
	*line = ft_strsub(*date, 0, *a - *date);
	(*a)++;
	(*a) = ft_strdup(*a);
	free(*date);
	*date = (*a);
	free(*str);
	return (1);
}

static int	ft_gnl_1(char **line, char **str, char **date, int fd)
{
	char	*a;
	int		ret;

	a = ft_strchr(*date, '\n');
	if (a != NULL)
		return (ft_gnl_firsttype(line, str, date, &a));
	else
	{
		while ((ret = read(fd, *str, BUFF_SIZE)) > 0)
		{
			(*str)[ret] = '\0';
			a = ft_strjoin(*date, *str);
			free(*date);
			*date = a;
			ft_strclr(*str);
			if (ft_strchr(*date, '\n'))
				break ;
		}
		free(*str);
		if (ret <= 0 && **date == '\0')
			return (0);
		return (ft_gnl_2(line, date));
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*date = NULL;
	int			ret;
	char		*str;

	str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, str, 0)) < 0)
	{
		free(str);
		return (-1);
	}
	*line = NULL;
	if (date == NULL)
	{
		ret = read(fd, str, BUFF_SIZE);
		str[ret] = '\0';
		date = ft_strdup(str);
		ft_strclr(str);
		if (*date == '\0')
			free(str);
		if (*date == '\0')
			return (0);
	}
	return (ft_gnl_1(line, &str, &date, fd));
}
