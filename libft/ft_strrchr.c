/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:00:56 by gansard           #+#    #+#             */
/*   Updated: 2022/12/01 17:37:56 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char) c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
