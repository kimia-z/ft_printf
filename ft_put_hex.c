/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kziari <kziari@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:01:08 by kziari            #+#    #+#             */
/*   Updated: 2023/11/20 15:46:57 by kziari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long long hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		len++;
		hex /= 16;
	}
	return (len);
}

char	*ft_hextoa(unsigned long long hex, char c)
{
	char	*str;
	int		len;

	len = ft_hexlen(hex);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		if (hex % 16 < 10)
			str[len - 1] = hex % 16 + '0';
		else
		{
			if (c == 'X')
				str[len - 1] = (hex % 16) - 10 + 'A';
			else
				str[len - 1] = (hex % 16) - 10 + 'a';
		}
		hex /= 16;
		len--;
	}
	return (str);
}
