/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kziari <kziari@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:22:55 by kziari            #+#    #+#             */
/*   Updated: 2023/11/20 15:45:48 by kziari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(int length, va_list args, char c)
{
	if (c == 'c')
		length = ft_char_print(length, va_arg(args, int));
	else if (c == 's')
		length = ft_str_print(length, va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		length = ft_dec_print(length, va_arg(args, int));
	else if (c == 'x' || c == 'X')
		length = ft_hex_print(length, va_arg(args, unsigned int), c);
	else if (c == 'p')
		length = ft_ptr_print(length, va_arg(args, unsigned long long));
	else if (c == 'u')
		length = ft_u_print(length, va_arg(args, unsigned int));
	else if (c == '%')
		length = ft_char_print(length, c);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	int		i;
	va_list	args;

	va_start(args, str);
	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length = ft_format(length, args, str[i + 1]);
			if (length == -1)
				return (-1);
			i++;
		}
		else
			length = ft_char_print(length, str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
