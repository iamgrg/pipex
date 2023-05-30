/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:45:53 by gansard           #+#    #+#             */
/*   Updated: 2022/11/24 09:12:50 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (checkset(s1[i], set))
		i++;
	while (checkset(s1[j], set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (j - i) + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, (j - i + 2));
	return (str);
}
