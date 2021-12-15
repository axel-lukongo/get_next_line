/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:24:39 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/15 18:08:22 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_alloc(char *str, int count)
{
	str = malloc(sizeof(char) * count + 1);
	if (!str)
	{
		free(str);
		return (0);
	}
	str[count] = '\0';
	return (str);
}

/*in this fonctions i look for a new line(\n) among the str*/
int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
			{
				return (NEW_LINE);
			}
			i++;
		}
	}
	return (NO_NEW_LINE);
}
/*this fonction do the most important work for the project.
first of all i use the variable size for get the number of the character
who i read before the \n and i add his value in count.
on line 46 if i did not find the \n among the character in the buffer,
i dive in recusursiv while i did not find the \n.
when i find the new line(\n), i malloc by count(he containe all character who
i read before the new line), and i start to copy the actual buf in str.
when he copied all caractere of the actual buff he trace back in recursive,
so the buff containe the previous elements so i copy this in str to.*/

char	*writting(int fd, int count, char *str)
{
	int				ret;
	int				size;
	static char		*rest;
	char			buf[BUFFER_SIZE + 1];

	size = 0;
	ret = 0;
	if (is_newline(rest) != NEW_LINE)
		ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	size = ft_strlen_nl(buf);
	if (count < ft_strlen_nl(rest))
		count += ft_strlen_nl(rest);
	count += size;
	if (is_newline(buf) == NO_NEW_LINE && ret == BUFFER_SIZE)
		str = writting(fd, count, str);
	else
	{
		str = ft_alloc(str, count);
		rest = cpy_rest(rest, str, buf);
	}
	while (size && count)
		str[--count] = buf[--size];
	return (str);
}

/*this is my principal fonction gnl.
the big part of the job is in the fonction writter*/
char	*get_next_line(int fd)
{
	char			*str;
	int				count;

	count = 0;
	str = NULL;
	str = writting(fd, count, str);
	if (*str == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
