/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:51:10 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/01 13:32:49 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int ft_printf(const char *str, ...);
int	get_format_specifier_index(char c);
int print_s(va_list args);
int print_c(va_list args);
int	ft_putnbr_fd(int n, int fd);






#endif