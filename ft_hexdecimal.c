/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:46:18 by itekir            #+#    #+#             */
/*   Updated: 2023/02/14 23:57:12 by itekir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_puthex(unsigned int n, char *base)
{
	if (n > 15)
	{
		ft_puthex(n / 16, base);
		ft_puthex(n % 16, base);
	}
	else
		write(1, &base[n], 1);
}

unsigned int	ft_hexdecimal(unsigned int n, char c)
{
	unsigned int	len;

	len = 0;
	if (c == 'X')
		ft_puthex(n, "0123456789ABCDEF");
	else if (c == 'x')
		ft_puthex(n, "0123456789abcdef");
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
