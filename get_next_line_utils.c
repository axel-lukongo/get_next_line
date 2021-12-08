/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:46 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/08 19:31:43 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

/*this is a strlen white a litle modification, he count the number of char
until the \n */
size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '\n')
		{
			s[i++];
		}
	}
	return (i);
}

char	*ft_strdup(char *s, char *src)
{
	int	i;

	i = 0;
	s = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!(s))
		return (0);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/*char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/

char	*cpy_rest(char *ptr, char *str, char *buff)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			str[i] = ptr[i];
			i++;
		}
	}
	if (is_newline(buff) == NEW_LINE)
		while (*buff == '\n')
			buff++;
	else
		while (*buff != '\n' || *buff == '\0')
			buff++;
	ptr = ft_strdup(ptr, buff);
	return (ptr);
}
