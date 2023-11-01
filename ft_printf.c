/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 06:43:39 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/01 13:34:56 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_c(va_list args)
{
    char c;
	
	c = va_arg(args, int);
	return(ft_putchar_fd(c, 1));
}

int print_s(va_list args)
{
    char *str;
	
	str = va_arg(args, char *);
	return(ft_putstr_fd(str, 1));
}

int	print_d_or_i(va_list args)
{
	int	num;
	
	// printf("enter func print_d_or_i\n");
	num = va_arg(args, int);
	return(ft_putnbr_fd(num, 1));
}

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
		[3] = print_d_or_i
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
	printf("returned value: %i\n", char_printed);
	return(0);
}

int main(void)
{
	char	*str;
	// printf("%i", ft_printf("test avec un char: %c", 'e'));
	
	ft_printf("char: %c\nstring: %s\nint(d): %d\nint(i): %i\n", 'u', "hello", 42, 24);
	// ft_printf("unsigned: %u\npointer: %p\nhex-min: %x\nhex-maj: %X\n%%: %%\n", 21, str, 1234567, 98765432);

	return(0);
}
// cspdiuxX%
