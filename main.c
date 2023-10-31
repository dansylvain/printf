/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 06:43:39 by dsylvain          #+#    #+#             */
/*   Updated: 2023/10/31 11:14:55 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "./libft/libft.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	while (*str)
	{
		if(*str == '%')
		{
			if (*(str + 1) == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (*(str + 1) == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (*(str + 1) == 'd' || *(str + 1) == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (*(str + 1) == 'u')
				write(1, "**unsigned**", 12); // unsigned. write a new func?
			if (*(str + 1) == 'p')
				write(1, "**pointer**", 11); 			// hexadecimal
			if (*(str + 1) == 'x')
				write(1, "**hexadecimal-min**", 19); 	// hexadecimal
			if (*(str + 1) == 'X')
				write(1, "**hexadecimal-maj**", 19); 	// hexadecimal
			if (*(str + 1) == '%')
				ft_putchar_fd('%', 1);
			str++;	
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return(0);
}

int main(void)
{
	char	*str;
	ft_printf("char: %c\nstring: %s\nint(i): %i\nint(d): %d\n", 'e', "hello", 42, 24);
	ft_printf("unsigned: %u\npointer: %p\nhex-min: %x\nhex-maj: %X\n%%: %%\n", 21, str, 1234567, 98765432);

	return(0);
}
// cspdiuxX%
