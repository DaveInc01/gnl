/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkhitar <dmkhitar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:26:20 by dmkhitar          #+#    #+#             */
/*   Updated: 2022/06/07 21:58:57 by dmkhitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s);
	i = 0;
	if (c > 127)
		return ((char *)s);
	if (s)
	{
		if (c == '\0')
			return ((char *)s + size);
		while (s[i])
		{
			if (s[i] == c)
				return ((char *)(s + i));
			i++;
		}
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*newstr;
	size_t		i;
	size_t		j;

	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = 0;
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*newstr;
	unsigned int	l;

	l = ft_strlen(s);
	if (start > l || len == 0)
		i = 0;
	else if (l < start + len)
		i = l - start;
	else
		i = len;
	newstr = malloc(i + 1);
	if (!newstr)
		return (0);
	l = 0;
	while (s[start] && l < i)
		newstr[l++] = s[start++];
	newstr[l] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *str)
{
	char	*newstr;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	newstr = malloc(len * sizeof(char));
	if (!newstr)
		return (NULL);
	i = -1;
	while (str[++i])
		newstr[i] = str[i];
	newstr[i] = 0;
	return (newstr);
}
