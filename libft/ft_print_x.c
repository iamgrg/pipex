/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:19:19 by gansard           #+#    #+#             */
/*   Updated: 2023/01/03 16:41:45 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(unsigned int num)
{
	char	*hex;
	char	*hex_digits;
	int		len;
	int		temp;

	len = digit_count(num);
	hex = malloc(sizeof(char) * len + 2);
	if (!hex)
		return (NULL);
	hex_digits = "0123456789abcdef";
	temp = len;
	while (num != 0)
	{
		hex[len] = hex_digits[num % 16];
		num /= 16;
		len--;
	}
	hex[temp + 1] = '\0';
	return (hex);
}

int	ft_print_x(unsigned int nb)
{
	char	*s;
	int		nb_bytes;

	if (nb == 0)
		return (write(1, "0", 1));
	s = ft_hex(nb);
	if (!s)
		return (0);
	nb_bytes = write(1, s, ft_strlen(s));
	free(s);
	return (nb_bytes);
}
