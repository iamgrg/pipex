/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:00:29 by gansard           #+#    #+#             */
/*   Updated: 2022/11/24 07:51:09 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*uc_src;
	unsigned char	*uc_dest;

	i = 0;
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		i++;
	}
	return (uc_dest);
}
