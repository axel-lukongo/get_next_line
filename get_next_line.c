/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:24:39 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/07 15:55:32 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

/*in this fonctions i look for a new line(\n) among the str*/
int	is_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (NEW_LINE);
		}
		i++;
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

char	*writting(int fd, int count)
{
	int			ret;
	char		*str;
	int			size;
	static char	buf[BUFFER_SIZE];

	size = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	size = ft_strlen(buf);
	count += size;
	if (is_newline(buf) == NO_NEW_LINE && ret != 0)
	{
		str = writting(fd, count);
	}
	else
	{
		str = malloc(sizeof(char) * count + 1);
		str[count] = '\0';
	}
	while (size && count)
		str[--count] = buf[--size];
	return (str);
}

/*this is my principal fonction gnl.
the big part of the job is in the fonction writter*/
char	*get_next_line(int fd)
{
	char	*str;
	int		count;

	count = 0;
	str = writting(fd, count);
	return (str);
}
