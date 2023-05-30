/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:07:09 by gansard           #+#    #+#             */
/*   Updated: 2023/01/26 11:29:28 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left(int fd, char *left)
{
	char	*buf;
	int		rd_bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr_gnl(left, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		left = ft_strjoin_gnl(left, buf);
	}
	free(buf);
	return (left);
}

char	*get_line(char *left)
{
	int		i;
	char	*str;

	i = 0;
	if (!left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		str[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		str[i] = left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_new_left(char *left)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		str[j++] = left[i++];
	str[j] = '\0';
	free(left);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left = get_left(fd, left);
	if (!left)
		return (NULL);
	line = get_line(left);
	left = get_new_left(left);
	return (line);
}
