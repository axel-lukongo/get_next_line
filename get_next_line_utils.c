/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:46 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/13 19:47:22 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

/*this is a strlen white a litle modification, he count the number of char
until the \n */
int	ft_strlen_nl(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '\n')
		{
			i++;
		}
		if (s[i] == '\n')
			i++;
	}
	return (i);
}

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

char	*ft_strdup(char *s, char *src, char *ptr)
{
	int		i;

	i = 0;
	if (src && src[0])
	{
		s = malloc(sizeof(char) * ft_strlen(src) + 1);
		if (!(s))
		{
			free(s);
			return (0);
		}
		while (src[i])
		{
			s[i] = src[i];
			i++;
		}
		s[i] = '\0';
		if (ptr)
			free(ptr);
	}
	if (*s == '\n')
		free(s);
	return (s);
}

char	*ft_strdup_r(char *src)
{
	int		i;
	char	*s;

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

char	*cpy_rest(char *rest, char *str, char *buff)
{
	int		i;
	char	*ptr;

	ptr = rest;
	i = 0;
	if (rest)
	{
		while (*rest && *rest != '\n')
		{
			str[i] = *rest;
			i++;
			rest++;
		}
		str[i] = *rest;
		while (*rest == '\n')
			rest++;
	}
	while (*buff != '\n' && *buff != '\0')
		buff++;
	while (*buff == '\n')
		buff++;
	if (ft_strlen(rest) == 0)
		rest = ft_strdup(rest, buff,ptr);
	else
	{
		rest = ft_strdup_r(rest);
		free(ptr);
	}
	return (rest);
}
