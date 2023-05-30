/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:19:13 by gansard           #+#    #+#             */
/*   Updated: 2023/01/03 16:44:45 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(long int nb)
{
	char	*hex;
	char	*s;
	int		nb_bytes;

	if (nb == 0)
		return (write(1, "(nil)", 5));
	hex = ft_atoi_hex(nb);
	if (!hex)
		return (0);
	s = ft_strjoin("0x", hex);
	free(hex);
	if (!s)
		return (0);
	nb_bytes = write(1, s, ft_strlen(s));
	free(s);
	return (nb_bytes);
}
