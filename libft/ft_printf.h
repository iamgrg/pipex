/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:23:35 by gansard           #+#    #+#             */
/*   Updated: 2023/02/18 11:28:24 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_print_d(int nb);
int					digit_count(long unsigned int nb);
int					ft_print_s(char *s);
int					ft_printf(const char *str, ...);
char				*ft_str(char *x, unsigned int number, long int len);
int					ft_len(int n);
int					ft_print_params(char *str, va_list args);
int					ft_print_reg(char *str);
int					ft_print_i(int nb);
int					ft_print_p(long int nb);
int					ft_print_u(unsigned int nb);
int					ft_print_x(unsigned int nb);
int					ft_print_majx(unsigned int nb);
int					ft_atoi(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);;
char				*ft_strchr(const char *s, int c);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
char				*ft_atoi_hex(long unsigned int num);
char				*ft_hex(unsigned int num);
char				*ft_uitoa(unsigned int n);

#endif