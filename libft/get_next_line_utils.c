/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:07:32 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 13:34:32 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *left, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left)
	{
		left = (char *)malloc(1 * sizeof(char));
		left[0] = '\0';
	}
	if (!left || !buf)
		return (NULL);
	str = malloc(sizeof(char)
			* ((ft_strlen_gnl(left) + ft_strlen_gnl(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left)
		while (left[++i] != '\0')
			str[i] = left[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen_gnl(left) + ft_strlen_gnl(buf)] = '\0';
	free(left);
	return (str);
}
