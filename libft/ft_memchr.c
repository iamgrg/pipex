/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:59:57 by gansard           #+#    #+#             */
/*   Updated: 2022/11/24 07:54:14 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	unsigned char	u_c;
	size_t			i;

	i = 0;
	s_tmp = (unsigned char *)s;
	u_c = (unsigned char) c;
	while (i < n)
	{
		if (s_tmp[i] == u_c)
			return ((unsigned char *) s + i);
		i++;
	}
	return (NULL);
}
