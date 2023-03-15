/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:25:15 by itekir            #+#    #+#             */
/*   Updated: 2023/02/13 23:23:03 by itekir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_putuns(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		ft_putuns(n / 10);
		ft_putuns(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

unsigned int	ft_print_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	ft_putuns(n);
	if (n == -0)
		return (1);
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
