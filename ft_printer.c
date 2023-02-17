/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:04:55 by itekir            #+#    #+#             */
/*   Updated: 2023/02/14 22:55:36 by itekir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		ft_putnbr(n);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

int unsigned	ft_print_number(int n)
{
	unsigned int	len;

	len = 0;
	ft_putnbr(n);
	if (n < 0 && n > -2147483648)
	{
		len++;
		n = -n;
	}
	else if (n == 0)
	{
		return (1);
	}
	else if (n == -2147483648)
	{
		return (11);
	}
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
