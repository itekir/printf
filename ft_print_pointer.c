/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:46:14 by itekir            #+#    #+#             */
/*   Updated: 2023/02/13 23:22:05 by itekir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_putptr(unsigned long long int n, char *base, int flag)
{
	if (flag == 0)
		write (1, "0x", 2);
	if (n > 15)
	{
		flag = 1;
		ft_putptr(n / 16, base, flag);
		ft_putptr(n % 16, base, flag);
	}
	else
		write (1, &base[n], 1);
}

unsigned int	ft_print_pointer(unsigned long long int n)
{
	unsigned int	len;

	len = 0;
	ft_putptr(n, "0123456789abcdef", 0);
	if (n == 0)
		return (3);
	while (n >= 1)
	{
		n = n / 16;
		len++;
	}
	return (len + 2);
}
	//+2 = 0x