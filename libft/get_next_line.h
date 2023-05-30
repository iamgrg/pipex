/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:07:25 by gansard           #+#    #+#             */
/*   Updated: 2023/01/26 11:28:26 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*get_left(int fd, char *left);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *left, char *buf);
size_t	ft_strlen_gnl(char *s);
char	*get_line(char *left);
char	*get_new_left(char *left);

#endif