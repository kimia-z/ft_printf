/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kziari <kziari@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:03:03 by kziari            #+#    #+#             */
/*   Updated: 2023/11/20 15:47:12 by kziari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uilen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	int		uilen;

	uilen = ft_uilen(n);
	result = malloc(sizeof(char) * (uilen + 1));
	if (!result)
		return (NULL);
	result[uilen] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[uilen - 1] = (n % 10) + '0';
		n /= 10;
		uilen--;
	}
	return (result);
}
