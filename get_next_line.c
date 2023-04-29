/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:11:03 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/06/07 22:24:50 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static t_info	d;
	int				p;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		p = read(fd, d.buffer, BUFFER_SIZE);
		if (p <= 0 && !(d.buff && *d.buff))
		{
			if (d.read == 1)
				free(d.tmp);
			return (0);
		}
		d.read = 1;
		d.buffer[p] = 0;
		retline(d.buffer, &d.buff, &d.tmp);
		if (ft_strchr(d.buff, '\n') || p == 0)
			break ;
	}
	line = divline(&d.buff);
	buff_increment(&d.buff);
	return (line);
}
