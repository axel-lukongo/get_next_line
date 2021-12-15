/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:26:36 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/14 14:38:20 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# define NO_NEW_LINE -1
# define NEW_LINE 1
# include<unistd.h>
# include<stdlib.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<stdio.h>

char	*get_next_line(int fd);
int		ft_strlen_nl(char *s);
char	*cpy_rest(char *ptr, char *str, char *buff);
int		ft_strlen(char *s);
int		is_newline(char *str);
#endif // !GET_NEXT_LINE_H
