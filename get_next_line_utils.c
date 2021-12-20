/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:46 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/20 19:39:00 by alukongo         ###   ########.fr       */
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

/*i allocat s(rest) for have a new address in memory
and i copy src(buf) to s(rest) at the end ptr still
have the old address of s so i free it*/
char	*ft_strdup_r(char *s, char *src, char *ptr)
{
	int		i;

	i = 0;
	if (src && src[0])
	{
		s = malloc(sizeof(char) * ft_strlen(src) + 2);
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
		while (i < ft_strlen(src) + 2)
			s[i++] = '\0';
		if (ft_strlen(ptr))
			free(ptr);
	}
	return (s);
}

/*it for move buf until his \n and when is done
i copy buf to rest white ft_strdup*/
char	*new_rest(char *rest, char *buf, char *ptr)
{
	while (*buf != '\n' && *buf != '\0')
		buf++;
	if (*buf == '\n')
		buf++;
	if (ft_strlen(rest) == 0)
	{
		rest = ft_strdup_r(rest, buf, ptr);
	}
	else
		rest = ft_strdup_r(rest, rest, ptr);
	return (rest);
}

//it for copy rest to str
char	*cpy(char *str, char *rest)
{
	int	i;

	i = 0;
	while (*rest && *rest != '\n')
	{
		str[i] = *rest;
		i++;
		rest++;
	}
	str[i] = *rest;
	rest++;
	return (rest);
}

/*this fonction allow me to copy the character in rest until the \n
and free the rest with ptr when i copy all*/
char	*cpy_rest(char *rest, char *str, char *buf)
{
	int		i;
	char	*ptr;

	ptr = rest;
	i = 0;
	if (rest)
	{
		if (*rest == '\n')
		{
			str[i] = *rest;
			rest++;
		}
		else
		{
			rest = cpy(str, rest);
		}
		if (!*rest)
		{
			free(ptr);
			ptr = NULL;
			rest = NULL;
		}
	}
	rest = new_rest(rest, buf, ptr);
	return (rest);
}
