/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:19:16 by gansard           #+#    #+#             */
/*   Updated: 2023/01/04 15:07:47 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nb)
{
	char	*s;
	int		nb_bytes;

	s = ft_uitoa(nb);
	if (!s)
		return (0);
	nb_bytes = write(1, s, ft_strlen(s));
	free(s);
	return (nb_bytes);
}
