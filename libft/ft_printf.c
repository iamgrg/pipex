/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:18:49 by gansard           #+#    #+#             */
/*   Updated: 2023/03/11 18:08:45 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_print_params(char *str, va_list args)
{
	char	c;

	if (*str == 'c')
	{
		c = (char)va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (*str == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_print_p(va_arg(args, long unsigned int)));
	else if (*str == 'd' || *str == 'i')
		return (ft_print_d(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_print_x(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_print_majx(va_arg(args, int)));
	else if (*str == '%')
		return (write(1, str, 1));
	return (0);
}

int	ft_print_reg(char *str)
{
	int		index_c;
	char	*ptr_c;

	ptr_c = ft_strchr(str, '%');
	if (!ptr_c)
		return (write(1, str, ft_strlen(str)));
	index_c = (int)(ptr_c - str);
	return (write(1, str, index_c));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	char	*s;
	va_list	args;

	s = (char *)ft_strdup(str);
	if (!s)
		return (0);
	i = 0;
	j = 0;
	va_start(args, str);
	while (s[i])
	{
		i += ft_print_reg(&s[i]);
		if (s[i] && s[i + 1])
		{
			j += ft_print_params(&s[i + 1], args) - 2;
			i += 2;
		}
	}
	free(s);
	va_end(args);
	return (i + j);
}
