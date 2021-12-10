/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:22:46 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/10 18:18:15 by alukongo         ###   ########.fr       */
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

char	*ft_strdup(char *s, char *src)
{
	int		i;

	i = 0;
	if (src)
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
	}
	return (s);
}

char	*cpy_rest(char *rest, char *str, char *buff)
{
	int		i;

	i = 0;
	if (rest)
	{
		while (*rest && *rest != '\n')
		{
			if (*rest != '\n')
				str[i] = *rest;
			/*rest = 0; i think the problem it because when i move *rest,
			 i did not delete the previous case of *rest and after,
			 this loops i put a new element in rest*/
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
		rest = ft_strdup(rest, buff);
	return (rest);
}
