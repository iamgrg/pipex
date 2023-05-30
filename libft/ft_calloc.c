/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:49:45 by gansard           #+#    #+#             */
/*   Updated: 2023/01/26 10:09:11 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (size && (nmemb > (((size_t) -1) / size)))
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, nmemb * size);
	return (str);
}
