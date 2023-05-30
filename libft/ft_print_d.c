/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:19:09 by gansard           #+#    #+#             */
/*   Updated: 2022/12/29 18:44:14 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int nb)
{
	char	*s;
	int		nb_bytes;

	s = ft_itoa(nb);
	if (!s)
		return (0);
	nb_bytes = write(1, s, ft_strlen(s));
	free(s);
	return (nb_bytes);
}
