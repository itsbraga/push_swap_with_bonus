/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:45:53 by panther           #+#    #+#             */
/*   Updated: 2024/02/16 17:05:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen_gnl(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*read_line;
	size_t	i;	

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (NULL);
	read_line = malloc(sizeof(char) * (ft_strlen_gnl(line)
				+ ft_strlen_gnl(buffer) + 1));
	if (!read_line)
		return (NULL);
	i = -1;
	while (++i < ft_strlen_gnl(line))
		read_line[i] = line[i];
	i = -1;
	while (++i < ft_strlen_gnl(buffer))
		read_line[ft_strlen_gnl(line) + i] = buffer[i];
	read_line[ft_strlen_gnl(line) + ft_strlen_gnl(buffer)] = '\0';
	free(line);
	return (read_line);
}

char	*extract_line(char *line)
{
	int		i;
	char	*read_line;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	read_line = malloc(sizeof(char) * (i + 2));
	if (!read_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		read_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		read_line[i] = line[i];
		i++;
	}
	read_line[i] = '\0';
	return (read_line);
}

char	*update_line(char *line)
{
	int		i;
	int		j;
	size_t	len_line;
	char	*updated;

	i = 0;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	len_line = ft_strlen_gnl(line);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	updated = malloc(sizeof(char) * (len_line - i + 1));
	if (!updated)
		return (NULL);
	j = 0;
	while (line[i])
		updated[j++] = line[i++];
	updated[j] = '\0';
	free(line);
	return (updated);
}
