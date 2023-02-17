/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:53:08 by itekir            #+#    #+#             */
/*   Updated: 2023/02/14 22:55:04 by itekir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_type(va_list *args, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_putchar(va_arg(*args, int));
	else if (type == 's')
		len += ft_print_string(va_arg(*args, char *));
	else if (type == 'p')
		len += ft_print_pointer(va_arg(*args, long long int));
	else if (type == 'i' || type == 'd')
		len += ft_print_number(va_arg(*args, int));
	else if (type == 'u')
		len += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (type == 'x' || type == 'X')
		len += ft_hexdecimal(va_arg(*args, unsigned long), type);
	else if (type == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *src, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			len += ft_type(&args, src[1 + i]);
			i++;
		}
		else
			len += ft_putchar(src[i]);
		i++;
	}
	va_end(args);
	return (len);
}
