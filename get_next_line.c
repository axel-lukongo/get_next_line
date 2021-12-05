/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:24:39 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/05 23:14:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	is_newline(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*writting(int fd, int i)
{
	int		ret;
	char	*str;
	char	buf[BUFFER_SIZE];

	ret = read(fd, buf, BUFFER_SIZE);
	if (is_newline(buf) != 1 && ret != 0)
	{
		i++;
		str = writting(fd, i);
		str[--i] = *buf;
	}
	if (is_newline(buf) == 1)
	{
		str = malloc(sizeof(char) * i + 1);
		str[i] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;
	int		count;
	
	count = 0;
	str = writting(fd, count);
	return (str);
}