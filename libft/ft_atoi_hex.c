/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:43:54 by gansard           #+#    #+#             */
/*   Updated: 2023/01/04 15:14:29 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	digit_count(long unsigned int nb)
{
	int	i;

	i = 0;
	nb = nb / 16;
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_atoi_hex(long unsigned int num)
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
