/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:15:25 by dan               #+#    #+#             */
/*   Updated: 2023/11/02 10:38:02 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_nbr_str_len(long int n)
{
	int	nbr_str_len;

	nbr_str_len = 0;
	if (n < 0)
	{
		nbr_str_len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		nbr_str_len++;
	}
	nbr_str_len++;
	return (nbr_str_len);
}

int	print_x_lowercase(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (!num)
		return (print_null(0));
	return (ft_put_hex(num, 1, 'x'));
}

int	print_x_uppercase(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (!num)
		return (print_null(0));
	return (ft_put_hex(num, 1, 'X'));
}

int	print_percent(va_list args)
{
	write(1, "%", 1);
	(void)args;
	return (1);
}

int	print_null(int zero_null_or_nil)
{
	if (zero_null_or_nil == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (zero_null_or_nil == 1)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else if (zero_null_or_nil == 2)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (0);
}
