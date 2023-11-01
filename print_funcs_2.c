/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:15:25 by dan               #+#    #+#             */
/*   Updated: 2023/11/01 16:32:54 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x_lowercase(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_put_hex(num, 1, 'x'));
}

int	print_x_uppercase(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_put_hex(num, 1, 'X'));
}
