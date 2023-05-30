/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:45:56 by gansard           #+#    #+#             */
/*   Updated: 2022/11/24 11:55:06 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	size_left;

	if (!s)
		return (NULL);
	i = 0;
	size_left = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (size_left < len)
		len = size_left;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
