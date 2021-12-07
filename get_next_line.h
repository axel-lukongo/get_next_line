/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:26:36 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/07 15:55:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 6
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
#endif // !GET_NEXT_LINE_H
