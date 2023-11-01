/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 06:43:39 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/01 15:39:58 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




int	get_index(char c)
{
	char	*format_specifiers = "csdiupxX%";
	int	i;
	
	i = 0;
	while (i < 9)
	{
		if (format_specifiers[i] == c)
			return(i);
		i++;
	}
	return(-1);
	
}

int ft_printf(const char *str, ...)
{
	int	char_printed;
	typedef int (*t_func_ptr)(va_list);
	
	char_printed = 0;
	t_func_ptr func_ptr[] = {
		[0] = print_c,
		[1] = print_s,
		[2] = print_d_or_i,
		[3] = print_d_or_i,
		[4] = print_u,
		[5] = print_p,
		[6] = print_x,
		[7] = print_X		
	};
	va_list args;
	va_start(args, str);
	while (*str)
	{
		if(*str == '%' && *(str + 1))
		{
			char_printed += (func_ptr[get_index(*(str + 1))](args));
			str++;	
		}
		else
		{
			ft_putchar_fd(*str, 1);
			char_printed++;
		}
		str++;
	}
	va_end(args);
	// printf("returned value: %i\n", char_printed);
	return(0);
}

int main(void)
{
	char	*str;
	// printf("%i", ft_printf("test avec un char: %c", 'e'));
	
	ft_printf("char: %c\nstring: %s\nint(d): %d\nint(i): %i\n", 'u', "hello", 42, 24);
	ft_printf("unsigned: %u\n", 45671);
	ft_printf("pointer: %p\n", str);
	ft_printf("x: %x\n", 2345678);
	ft_printf("X: %X\n", 87654334);
	// ft_printf("unsigned: %u\npointer: %p\nhex-min: %x\nhex-maj: %X\n%%: %%\n", 21, str, 1234567, 98765432);

	return(0);
}
// cspdiuxX%
