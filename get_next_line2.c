/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:26:40 by abestaev          #+#    #+#             */
/*   Updated: 2021/12/08 10:40:25 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(char **line, int end_line)
{
	char	*s;

	if (!*line || !**line)
	{
		if (*line)
		{
			free(*line);
			*line = (NULL);
		}
		return (NULL);
	}
	if (end_line == -1)
		end_line = ft_strlen(*line);
	s = ft_substr(*line, 0, end_line + 1, 0);
	*line = ft_substr(*line, end_line + 1, ft_strlen(*line), 1);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*line;
	int			end_line;
	int			result;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	end_line = ft_find_newline(line);
	if (end_line == -1)
		result = read(fd, buf, BUFFER_SIZE);
	while (end_line == -1 && result > 0)
	{
		buf[result] = '\0';
		line = ft_strjoin(line, buf);
		end_line = ft_find_newline(line);
		if (end_line == -1)
			result = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (get_the_line(&line, end_line));
}
