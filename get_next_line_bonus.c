/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:25:51 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/06/07 22:32:59 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	retline(char *buffer, char **buff, char **tmp)
{
	if (!(*buff))
		*buff = ft_strdup(buffer);
	else
	{
		*buff = ft_strjoin(*buff, buffer);
		free(*tmp);
	}
	*tmp = *buff;
}

char	*divline(char **buff)
{
	long	linelen;
	char	*line;

	if (ft_strchr(*buff, '\n'))
	{
		linelen = (ft_strchr(*buff, '\n') - *buff) + 1;
		line = ft_substr(*buff, 0, linelen);
		*buff = ft_strchr(*buff, '\n');
	}
	else
		line = ft_strdup(*buff);
	return (line);
}

void	buff_increment(char **dbuff)
{
	if (ft_strchr(*dbuff, '\n'))
		*dbuff = *dbuff + 1;
	else
		*dbuff += ft_strlen(*dbuff);
}

char	*get_next_line(int fd)
{
	static t_info	d[OPEN_MAX];
	int				p;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		p = read(fd, d[fd].buffer, BUFFER_SIZE);
		if (p <= 0 && !(d[fd].buff && *d[fd].buff))
		{
			if (d[fd].read == 1)
				free(d[fd].tmp);
			return (0);
		}
		d[fd].read = 1;
		d[fd].buffer[p] = 0;
		retline(d[fd].buffer, &d[fd].buff, &d[fd].tmp);
		if (ft_strchr(d[fd].buff, '\n') || p == 0)
			break ;
	}
	line = divline(&d[fd].buff);
	buff_increment(&d[fd].buff);
	return (line);
}
