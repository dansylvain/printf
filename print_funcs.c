/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:14 by dan               #+#    #+#             */
/*   Updated: 2023/11/01 15:43:25 by dan              ###   ########.fr       */
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

int	print_u(va_list args)
{
	unsigned int	num;
	
	// printf("enter func print_d_or_i\n");
	num = (unsigned int)va_arg(args, unsigned int);
	return(ft_putunbr_fd(num, 1));
}

int	print_p(va_list args)
{
	void *ptr;
    unsigned long addr;
    int count = 0;

    ptr = va_arg(args, void *);
    addr = (unsigned long)ptr;

    count += ft_putstr_fd("0x", 1);
    count += ft_put_hex(addr, 1, 'x');
    return count;
}

int	print_x(va_list args)
{
	unsigned int	num = va_arg(args, unsigned int);
	
	return(ft_put_hex(num, 1, 'x'));
}

int	print_X(va_list args)
{
	unsigned int	num = va_arg(args, unsigned int);
	
	return(ft_put_hex(num, 1, 'X'));}