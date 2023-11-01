/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:51:10 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/01 15:38:25 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *str, ...);
int	get_format_specifier_index(char c);


int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_put_hex(unsigned long n, int fd, char case_type);


int print_c(va_list args);
int print_s(va_list args);
int	print_d_or_i(va_list args);
int	print_u(va_list args);
int	print_p(va_list args);
int	print_x(va_list args);
int	print_X(va_list args);





#endif