/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kziari <kziari@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:57:44 by kziari            #+#    #+#             */
/*   Updated: 2023/11/20 15:46:26 by kziari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_print(int length, const char *str)
{
	size_t	len;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (length + 6);
	}
	len = ft_strlen(str);
	length += len;
	write (1, str, len);
	return (length);
}

int	ft_dec_print(int length, int num)
{
	char	*result;

	result = ft_itoa(num);
	if (result == NULL)
		return (-1);
	length = ft_str_print (length, result);
	free (result);
	return (length);
}

int	ft_hex_print(int length, unsigned int hex, char c)
{
	char	*result;

	result = ft_hextoa(hex, c);
	if (result == NULL)
		return (-1);
	length = ft_str_print (length, result);
	free(result);
	return (length);
}

int	ft_ptr_print(int length, unsigned long long hex)
{
	char	*result;

	if (hex == 0)
	{
		write (1, "(nil)", 5);
		return (length + 5);
	}
	result = ft_hextoa(hex, 'x');
	if (result == NULL)
		return (-1);
	length = ft_char_print (length, '0');
	length = ft_char_print (length, 'x');
	length = ft_str_print (length, result);
	free (result);
	return (length);
}

int	ft_u_print(int length, unsigned int ui)
{
	char	*result;

	result = ft_uitoa(ui);
	if (result == NULL)
		return (-1);
	length = ft_str_print(length, result);
	free (result);
	return (length);
}
