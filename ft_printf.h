/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itekir <itekir@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:37:25 by itekir            #+#    #+#             */
/*   Updated: 2023/02/14 22:38:41 by itekir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *src, ...);
int				ft_putchar(int c);
int				ft_print_string(char *str);
unsigned int	ft_print_pointer(unsigned long long int n);
int unsigned	ft_print_number(int n);
unsigned int	ft_print_unsigned(unsigned int n);
unsigned int	ft_hexdecimal(unsigned int n, char c);
int				ft_print_percecnt(void);

#endif