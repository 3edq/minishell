/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:28 by ksaegusa          #+#    #+#             */
/*   Updated: 2025/02/04 19:35:51 by ksaegusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

static char	*extract_line(char *buffer)
{
	size_t	count;
	char	*line;

	count = 0;
	if (!buffer[count])
		return (NULL);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	line = ft_substr(buffer, 0, count + (buffer[count] == '\n'));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	return (line);
}

static char	*extract_remainder(char *buffer)
{
	size_t	count;
	char	*remain;

	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
	{
		free(buffer);
		return (NULL);
	}
	remain = ft_strdup(buffer + count + 1);
	free(buffer);
	return (remain);
}

static char	*read_and_store(int fd, char *buffer, char *buf)
{
	int		read_bytes;
	char	*tmp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		tmp = ft_strjoin(buffer, buf);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
		free(buffer);
		buffer = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buffer);
}

static char	*read_append(int fd, char *buffer)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(buffer);
		return (NULL);
	}
	buffer = read_and_store(fd, buffer, buf);
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (NULL);
	}
	buffer = read_append(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = extract_remainder(buffer);
	return (line);
}
