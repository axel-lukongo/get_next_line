/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:26:36 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/08 19:31:11 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3
# define NO_NEW_LINE -1
# define NEW_LINE 1
# include<unistd.h>
# include<stdlib.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*cpy_rest(char *ptr, char *str, char *buff);
int	is_newline(char *str);
#endif // !GET_NEXT_LINE_H
