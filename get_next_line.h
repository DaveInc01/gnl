/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:52:43 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/06/07 21:23:39 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	char		buffer[BUFFER_SIZE + 1];
	char		*buff;
	char		*tmp;
	int			read;
}	t_info;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);

#endif
