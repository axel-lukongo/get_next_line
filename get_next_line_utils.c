/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:46 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/09 17:13:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

/*this is a strlen white a litle modification, he count the number of char
until the \n */
size_t	ft_strlen_nl(char *s)
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

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			s[i++];
		}
	}
	return (i);
}

char	*ft_strdup(char *s, char *src)
{
	int		i;
	char	tes;

	i = 0;
	s = malloc(sizeof(char) * ft_strlen_nl(src) + 1);
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

char	*cpy_rest(char *rest, char *str, char *buff)
{
	int	i;

	i = 0;
	if (rest)
	{
		while (*rest && *rest != '\n')
		{
			if (*rest != '\n')
				str[i] = *rest;
			i++;
			rest++;
		}
		while (*rest == '\n')
			rest++;
	}
	while (*buff != '\n' && *buff != '\0')
		buff++;
	while (*buff == '\n')
		buff++;
	if (ft_strlen(rest) == 0)
		rest = ft_strdup(rest, buff);
	return (rest);
}
