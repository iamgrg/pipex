/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:00:53 by gansard           #+#    #+#             */
/*   Updated: 2022/11/24 07:22:06 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_string(const char *s, const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != str[i] || i == len)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little[0])
		return ((char *) &big[i]);
	while (big[i] && i < len)
	{
		if (check_string(little, &big[i], len - i))
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
