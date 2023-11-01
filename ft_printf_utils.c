/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:46:31 by dsylvain          #+#    #+#             */
/*   Updated: 2023/11/01 13:36:08 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return(i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return(1);
}

int	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	int	i;

	i = 0;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		i++;
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((num % 10) + '0', fd);
	i++;
	return(i);
}