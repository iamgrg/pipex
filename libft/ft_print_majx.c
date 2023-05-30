/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_majx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:29:37 by gansard           #+#    #+#             */
/*   Updated: 2023/02/21 13:33:05 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_majx(unsigned int nb)
{
	char	*s;
	int		i;
	int		nb_bytes;

	if (nb == 0)
		return (write(1, "0", 1));
	s = ft_hex(nb);
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		s[i] -= 32;
		i++;
	}
	nb_bytes = write(1, s, ft_strlen(s));
	free(s);
	return (nb_bytes);
}
